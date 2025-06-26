import numpy as np
import math

np.set_printoptions(precision=15)

def seebatt(v):
    """
    Recursion algorithms needed by the lambertbattin routine
    """
    c = np.array([
        0.2,
        9.0/35.0,
        16.0/63.0,
        25.0/99.0,
        36.0/143.0,
        49.0/195.0,
        64.0/255.0,
        81.0/323.0,
        100.0/399.0,
        121.0/483.0,
        144.0/575.0,
        169.0/675.0,
        196.0/783.0,
        225.0/899.0,
        256.0/1023.0,
        289.0/1155.0,
        324.0/1295.0,
        361.0/1443.0,
        400.0/1599.0,
        441.0/1763.0,
        484.0/1935.0
    ])
    
    sqrtopv = math.sqrt(1.0 + v)
    eta = v / (1.0 + sqrtopv)**2
    
    # Process forwards
    delold = 1.0
    termold = c[0]
    sum1 = termold
    i = 0 # lo empiezo en 0 mejor
    
    while i < 20 and abs(termold) > 1e-8:
        del_val = 1.0 / (1.0 + c[i+1] * eta * delold)
        term = termold * (del_val - 1.0)
        sum1 = sum1 + term
        i = i + 1
        delold = del_val
        termold = term
    
    seebat = 1.0 / ((1.0/(8.0*(1.0+sqrtopv))) * (3.0 + sum1 / (1.0+eta*sum1)))
    return seebat

def seebattk(v):
    """
    Recursion algorithms needed by the lambertbattin routine
    """
    d = np.array([
        1.0/3.0,
        4.0/27.0,
        8.0/27.0,
        2.0/9.0,
        22.0/81.0,
        208.0/891.0,
        340.0/1287.0,
        418.0/1755.0,
        598.0/2295.0,
        700.0/2907.0,
        928.0/3591.0,
        1054.0/4347.0,
        1330.0/5175.0,
        1480.0/6075.0,
        1804.0/7047.0,
        1978.0/8091.0,
        2350.0/9207.0,
        2548.0/10395.0,
        2968.0/11655.0,
        3190.0/12987.0,
        3658.0/14391.0
    ])
    
    # Process forwards
    sum1 = d[0]
    delold = 1.0
    termold = d[0]
    i = 0
    # Siempre entrara la primera iteración (por eso de que en matlab es do while)
    while i <= 20 and abs(termold) > 1e-6:
        del_val = 1.0 / (1.0 + d[i+1] * v * delold)
        term = termold * (del_val - 1.0)
        sum1 = sum1 + term
        i = i + 1
        delold = del_val
        termold = term
    
    return sum1

def lambert_battin(ro, r, dm, dtsec):
    """
    Resuelve el problema de Lambert utilizando el método de Battin.
    
    Inputs:
        ro      - IJK Position vector 1 [m]
        r       - IJK Position vector 2 [m] 
        dm      - direction of motion ('pro', 'retro')
        dtsec   - Time between ro and r [s]
    
    Outputs:
        vo      - IJK Velocity vector [m/s]
        v       - IJK Velocity vector [m/s]
    """
    
    ro = np.array(ro, dtype=np.float64)
    r = np.array(r, dtype=np.float64)

    small = 1.0e-6
    mu = 3.986004418e14  # m3/s2
    y1 = 0.0
    
    magr = np.linalg.norm(r)
    magro = np.linalg.norm(ro)
    cos_delta_nu = np.dot(ro, r) / (magro * magr)
    rcrossr = np.cross(ro, r)
    magrcrossr = np.linalg.norm(rcrossr)
    
    if dm == 'pro':
        sin_delta_nu = magrcrossr / (magro * magr)
    else:
        sin_delta_nu = -magrcrossr / (magro * magr)
    
    dnu = math.atan2(sin_delta_nu, cos_delta_nu)
    
    # The angle needs to be positive to work for the long way
    if dnu < 0.0:
        dnu = 2.0 * math.pi + dnu
    
    ror = magr / magro
    eps = ror - 1.0
    tan2w = 0.25 * eps * eps / (math.sqrt(ror) + ror * (2.0 + math.sqrt(ror)))
    rp = math.sqrt(magro * magr) * ((math.cos(dnu * 0.25))**2 + tan2w)
    
    if dnu < math.pi:
        L = ((math.sin(dnu * 0.25))**2 + tan2w) / \
            ((math.sin(dnu * 0.25))**2 + tan2w + math.cos(dnu * 0.5))
    else:
        L = ((math.cos(dnu * 0.25))**2 + tan2w - math.cos(dnu * 0.5)) / \
            ((math.cos(dnu * 0.25))**2 + tan2w)
    
    m = mu * dtsec * dtsec / (8.0 * rp * rp * rp)
    x = 10.0
    xn = L
    chord = math.sqrt(magro * magro + magr * magr - 2.0 * magro * magr * math.cos(dnu))
    s = (magro + magr + chord) * 0.5
    lim1 = math.sqrt(m / L)
    
    loops = 1
    while True:
        x = xn
        tempx = seebatt(x)
        denom = 1.0 / ((1.0 + 2.0*x + L) * (4.0*x + tempx*(3.0 + x)))
        h1 = (L + x)**2 * (1.0 + 3.0*x + tempx) * denom
        h2 = m * (x - L + tempx) * denom
        
        # Evaluate CUBIC
        b = 0.25 * 27.0 * h2 / ((1.0 + h1)**3)
        
        if b < -1.0:  # reset the initial condition
            xn = 1.0 - 2.0 * L
        else:
            if y1 > lim1:
                xn = xn * (lim1 / y1)
            else:
                u = 0.5 * b / (1.0 + math.sqrt(1.0 + b))
                k2 = seebattk(u)
                y = ((1.0 + h1) / 3.0) * (2.0 + math.sqrt(1.0 + b) / (1.0 + 2.0*u*k2*k2))
                xn = math.sqrt(((1.0 - L) * 0.5)**2 + m/(y*y)) - (1.0 + L) * 0.5
        
        loops = loops + 1
        y1 = math.sqrt(m / ((L + x) * (1.0 + x)))
        
        if (abs(xn - x) < small) or (loops > 30):
            break
    
    a = mu * dtsec * dtsec / (16.0 * rp * rp * xn * y * y)
    
    # Find Eccentric anomalies
    # Hyperbolic
    if a < -small:
        arg1 = math.sqrt(s / (-2.0 * a))
        arg2 = math.sqrt((s - chord) / (-2.0 * a))
        # Evaluate f and g functions
        alph = 2.0 * math.asinh(arg1)
        beth = 2.0 * math.asinh(arg2)
        dh = alph - beth
        f = 1.0 - (a/magro) * (1.0 - math.cosh(dh))
        gdot = 1.0 - (a/magr) * (1.0 - math.cosh(dh))
        g = dtsec - math.sqrt(-a*a*a/mu) * (math.sinh(dh) - dh)
    else:
        # Elliptical
        if a > small:
            arg1 = math.sqrt(s / (2.0 * a))
            arg2 = math.sqrt((s - chord) / (2.0 * a))
            sinv = arg2
            cosv = math.sqrt(1.0 - (magro + magr - chord)/(4.0 * a))
            bete = 2.0 * math.acos(cosv)
            bete = 2.0 * math.asin(sinv)
            
            if dnu > math.pi:
                bete = -bete
            
            cosv = math.sqrt(1.0 - s/(2.0 * a))
            sinv = arg1
            am = s * 0.5
            ae = math.pi
            be = 2.0 * math.asin(math.sqrt((s - chord)/s))
            tm = math.sqrt(am*am*am/mu) * (ae - (be - math.sin(be)))
            
            if dtsec > tm:
                alpe = 2.0 * math.pi - 2.0 * math.asin(sinv)
            else:
                alpe = 2.0 * math.asin(sinv)
            
            de = alpe - bete
            f = 1.0 - (a/magro) * (1.0 - math.cos(de))
            gdot = 1.0 - (a/magr) * (1.0 - math.cos(de))
            g = dtsec - math.sqrt(a*a*a/mu) * (de - math.sin(de))
        else:
            # Parabolic
            # porque en matlab arg1 = arg2 = 0.0 ??
            raise ValueError("a parabolic orbit")
    
    vo = (r - f * ro) / g
    v = (gdot * r - ro) / g
    
    return vo, v

def test_lambert_battin():
    r1 = np.array([20.0e6, 20.0e6, 0])  # [m]
    r2 = np.array([-20.0e6, 10.0e6, 0])  # [m]
    tof = 1.0 * 86400  # [s] (1 dia)
    
    v1, v2 = lambert_battin(r1, r2, 'retro', tof)
    
    print(f"V1 = {v1}")
    print(f"V2 = {v2}")
    
    return v1, v2

if __name__ == "__main__":
    test_lambert_battin()