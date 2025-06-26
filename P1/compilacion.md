astiod.cpp: In function ‘void anglesgauss(double, double, double, double, double, double, double, double, double, double*, double*, double*, double*, double*)’:
astiod.cpp:195:48: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  195 |   std::vector< std::vector<double> > lmatii(3,3), cmat(3,3), rhomat(3,3),
      |                                                ^
In file included from /usr/include/c++/13/vector:66,
                 from astmath.h:27,
                 from astiod.h:37,
                 from astiod.cpp:32:
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/13/bits/stl_algobase.h:65,
                 from /usr/include/c++/13/bits/specfun.h:43,
                 from /usr/include/c++/13/cmath:3699,
                 from /usr/include/c++/13/math.h:36,
                 from astiod.h:35:
/usr/include/c++/13/bits/stl_iterator_base_types.h: In substitution of ‘template<class _InIter> using std::_RequireInputIter = std::__enable_if_t<std::is_convertible<typename std::iterator_traits< <template-parameter-1-1> >::iterator_category, std::input_iterator_tag>::value> [with _InIter = int]’:
/usr/include/c++/13/bits/stl_vector.h:705:9:   required from here
/usr/include/c++/13/bits/stl_iterator_base_types.h:250:11: error: no type named ‘iterator_category’ in ‘struct std::iterator_traits<int>’
  250 |     using _RequireInputIter =
      |           ^~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astiod.cpp:195:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  195 |   std::vector< std::vector<double> > lmatii(3,3), cmat(3,3), rhomat(3,3),
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astiod.cpp:195:72: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  195 |   std::vector< std::vector<double> > lmatii(3,3), cmat(3,3), rhomat(3,3),
      |                                                                        ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astiod.cpp:196:19: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  196 |          lmati(3,3), rsmat(3,3), lir(3,3);
      |                   ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astiod.cpp:196:31: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  196 |          lmati(3,3), rsmat(3,3), lir(3,3);
      |                               ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astiod.cpp:196:41: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  196 |          lmati(3,3), rsmat(3,3), lir(3,3);
      |                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astmath.cpp: In function ‘void ludecomp(std::vector<std::vector<double> >&, std::vector<int>&, int)’:
astmath.cpp:838:56: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  838 |      std::vector< std::vector<double> > scale(order+1,2);
      |                                                        ^
In file included from /usr/include/c++/13/vector:66,
                 from astmath.h:27,
                 from astmath.cpp:33:
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/13/bits/stl_algobase.h:65,
                 from /usr/include/c++/13/bits/specfun.h:43,
                 from /usr/include/c++/13/cmath:3699,
                 from /usr/include/c++/13/math.h:36,
                 from astmath.h:25:
/usr/include/c++/13/bits/stl_iterator_base_types.h: In substitution of ‘template<class _InIter> using std::_RequireInputIter = std::__enable_if_t<std::is_convertible<typename std::iterator_traits< <template-parameter-1-1> >::iterator_category, std::input_iterator_tag>::value> [with _InIter = int]’:
/usr/include/c++/13/bits/stl_vector.h:705:9:   required from here
/usr/include/c++/13/bits/stl_iterator_base_types.h:250:11: error: no type named ‘iterator_category’ in ‘struct std::iterator_traits<int>’
  250 |     using _RequireInputIter =
      |           ^~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astmath.cpp: In function ‘void matinverse(std::vector<std::vector<double> >, int, std::vector<std::vector<double> >&)’:
astmath.cpp:1015:60: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
 1015 |       std::vector< std::vector<double> > lu(order+1,order+1);
      |                                                            ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
astmath.cpp:1016:54: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
 1016 |       std::vector< std::vector<double> >  b(order+1,2);
      |                                                      ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
asttime.cpp: In function ‘int getmon(char*)’:
asttime.cpp:46:6: error: ‘strcpy’ was not declared in this scope
   46 |      strcpy(monstr[1], "Jan");
      |      ^~~~~~
asttime.cpp:33:1: note: ‘strcpy’ is defined in header ‘<cstring>’; did you forget to ‘#include <cstring>’?
   32 | #include "asttime.h"
  +++ |+#include <cstring>
   33 | 
asttime.cpp:60:14: error: ‘strcmp’ was not declared in this scope
   60 |      while ((strcmp(instr, monstr[ktr])!=0) && (ktr <=12))
      |              ^~~~~~
asttime.cpp:60:14: note: ‘strcmp’ is defined in header ‘<cstring>’; did you forget to ‘#include <cstring>’?
asttime.cpp: In function ‘int getday(char*)’:
asttime.cpp:78:6: error: ‘strcpy’ was not declared in this scope
   78 |      strcpy(monstr[1], "Sun");
      |      ^~~~~~
asttime.cpp:78:6: note: ‘strcpy’ is defined in header ‘<cstring>’; did you forget to ‘#include <cstring>’?
asttime.cpp:87:14: error: ‘strcmp’ was not declared in this scope
   87 |      while ((strcmp(instr, monstr[ktr])!=0) && (ktr <=7))
      |              ^~~~~~
asttime.cpp:87:14: note: ‘strcmp’ is defined in header ‘<cstring>’; did you forget to ‘#include <cstring>’?
coordfk5.cpp: In function ‘void iau76fk5_itrf_gcrf(double*, double*, double*, edirection, double*, double*, double*, iau80data&, char, double, double, double, double, double, int, double, double, double, double, std::vector<std::vector<double> >)’:
coordfk5.cpp:200:56: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  200 |        std::vector< std::vector<double> > prec, nut(3,3), st, stdot, pm, pmp,
      |                                                        ^
In file included from /usr/include/c++/13/vector:66,
                 from coordfk5.h:35,
                 from coordfk5.cpp:34:
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/13/bits/stl_algobase.h:65,
                 from /usr/include/c++/13/bits/specfun.h:43,
                 from /usr/include/c++/13/cmath:3699,
                 from /usr/include/c++/13/math.h:36,
                 from coordfk5.h:34:
/usr/include/c++/13/bits/stl_iterator_base_types.h: In substitution of ‘template<class _InIter> using std::_RequireInputIter = std::__enable_if_t<std::is_convertible<typename std::iterator_traits< <template-parameter-1-1> >::iterator_category, std::input_iterator_tag>::value> [with _InIter = int]’:
/usr/include/c++/13/bits/stl_vector.h:705:9:   required from here
/usr/include/c++/13/bits/stl_iterator_base_types.h:250:11: error: no type named ‘iterator_category’ in ‘struct std::iterator_traits<int>’
  250 |     using _RequireInputIter =
      |           ^~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp: In function ‘void iau76fk5all_itrf_gcrf(double*, double*, double*, edirection, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, iau80data&, char, double, double, double, double, double, int, double, double, double, double, std::vector<std::vector<double> >)’:
coordfk5.cpp:371:56: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  371 |        std::vector< std::vector<double> > prec, nut(3,3), st, stdot, pm, pmp,
      |                                                        ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp:375:15: error: declaration of ‘double rpef [3]’ shadows a parameter
  375 |               rpef[3], vpef[3], apef[3], omgxv[3], tempvec1[3], tempvec[3];
      |               ^~~~
coordfk5.cpp:357:15: note: ‘double* rpef’ previously declared here
  357 |        double rpef[3], double vpef[3], double apef[3],
      |        ~~~~~~~^~~~~~~
coordfk5.cpp:375:24: error: declaration of ‘double vpef [3]’ shadows a parameter
  375 |               rpef[3], vpef[3], apef[3], omgxv[3], tempvec1[3], tempvec[3];
      |                        ^~~~
coordfk5.cpp:357:31: note: ‘double* vpef’ previously declared here
  357 |        double rpef[3], double vpef[3], double apef[3],
      |                        ~~~~~~~^~~~~~~
coordfk5.cpp:375:33: error: declaration of ‘double apef [3]’ shadows a parameter
  375 |               rpef[3], vpef[3], apef[3], omgxv[3], tempvec1[3], tempvec[3];
      |                                 ^~~~
coordfk5.cpp:357:47: note: ‘double* apef’ previously declared here
  357 |        double rpef[3], double vpef[3], double apef[3],
      |                                        ~~~~~~~^~~~~~~
coordfk5.cpp: In function ‘void iau76fk5_itrf_teme(double*, double*, double*, edirection, double*, double*, double*, double, double, double, double, double, std::vector<std::vector<double> >&)’:
coordfk5.cpp:797:49: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  797 |        std::vector< std::vector<double> > st(3,3), stdot(3,3), pm, temp(3,3), tempmat(3,3),
      |                                                 ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp:797:61: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  797 |        std::vector< std::vector<double> > st(3,3), stdot(3,3), pm, temp(3,3), tempmat(3,3),
      |                                                             ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp:797:76: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  797 |        std::vector< std::vector<double> > st(3,3), stdot(3,3), pm, temp(3,3), tempmat(3,3),
      |                                                                            ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp:797:90: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  797 |        std::vector< std::vector<double> > st(3,3), stdot(3,3), pm, temp(3,3), tempmat(3,3),
      |                                                                                          ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp: In function ‘void teme_pef(double*, double*, double*, edirection, double*, double*, double*, double)’:
coordfk5.cpp:1262:50: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
 1262 |         std::vector< std::vector<double> > tm(3,3), tmp;
      |                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp: In function ‘void truemean(double, int, int, char, iau80data&, std::vector<std::vector<double> >&)’:
coordfk5.cpp:2114:50: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
 2114 |        std::vector< std::vector<double> > nut(3,3), st(3,3);
      |                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
coordfk5.cpp:2114:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
 2114 |        std::vector< std::vector<double> > nut(3,3), st(3,3);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
In file included from sgp4dc.cpp:23:
sgp4dc.h:37:75: warning: extra tokens at end of #include directive
   37 | #include "astiod.h"                                                       `
      |                                                                           ^
sgp4dc.cpp: In function ‘void dsvbksb(std::vector<std::vector<double> >, std::vector<std::vector<double> >, std::vector<std::vector<double> >, int, int, std::vector<std::vector<double> >, std::vector<std::vector<double> >&)’:
sgp4dc.cpp:95:51: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
   95 |         std::vector< std::vector<double> > tmp(n,1);
      |                                                   ^
In file included from /usr/include/c++/13/vector:66,
                 from sgp4dc.h:30:
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/13/bits/stl_algobase.h:65,
                 from /usr/include/c++/13/bits/specfun.h:43,
                 from /usr/include/c++/13/cmath:3699,
                 from /usr/include/c++/13/math.h:36,
                 from sgp4dc.h:29:
/usr/include/c++/13/bits/stl_iterator_base_types.h: In substitution of ‘template<class _InIter> using std::_RequireInputIter = std::__enable_if_t<std::is_convertible<typename std::iterator_traits< <template-parameter-1-1> >::iterator_category, std::input_iterator_tag>::value> [with _InIter = int]’:
/usr/include/c++/13/bits/stl_vector.h:705:9:   required from here
/usr/include/c++/13/bits/stl_iterator_base_types.h:250:11: error: no type named ‘iterator_category’ in ‘struct std::iterator_traits<int>’
  250 |     using _RequireInputIter =
      |           ^~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp: In function ‘void findatwaatwb(int, int, int, double, double, gravconsttype, elsetrec, obsrec*, char, std::vector<std::vector<double> >&, std::vector<double>&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&)’:
sgp4dc.cpp:797:50: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  797 |      std::vector< std::vector<double> > trans(3,3);
      |                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:801:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  801 |      std::vector< std::vector<double> > a(indobs,statesize);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:802:60: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  802 |      std::vector< std::vector<double> > at(statesize,indobs);
      |                                                            ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:803:68: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  803 |      std::vector< std::vector<double> > atwaacc(statesize,statesize);
      |                                                                    ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:804:60: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  804 |      std::vector< std::vector<double> > atwbacc(statesize,1);
      |                                                            ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:817:16: error: expected ‘:’ before ‘,’ token
  817 |          case 1,3 : indobs= 2;
      |                ^
      |                :
sgp4dc.cpp:817:16: error: expected primary-expression before ‘,’ token
sgp4dc.cpp: In function ‘void leastsquares(double, double, double, gravconsttype, elsetrec&, elsetrec, char, char, int, int, int, obsrec*, int&, std::vector<std::vector<double> >&, std::vector<double>&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, std::vector<std::vector<double> >&, FILE*, FILE*)’:
sgp4dc.cpp:1277:65: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1277 |      std::vector< std::vector<double> > tmmp(statesize,statesize);
      |                                                                 ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1278:51: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
 1278 |      std::vector< std::vector<double> > b(indobs,1);
      |                                                   ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1279:61: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1279 |      std::vector< std::vector<double> > atw(statesize,indobs);
      |                                                             ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1280:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1280 |      std::vector< std::vector<double> > u(statesize,indobs);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1281:51: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
 1281 |      std::vector< std::vector<double> > w(indobs,1);
      |                                                   ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1282:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
 1282 |      std::vector< std::vector<double> > wutatwb(indobs,1);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1283:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1283 |      std::vector< std::vector<double> > ww(indobs,indobs);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1284:56: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1284 |      std::vector< std::vector<double> > v(indobs,indobs);
      |                                                        ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1285:61: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1285 |      std::vector< std::vector<double> > ut(indobs, statesize);
      |                                                             ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1286:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1286 |      std::vector< std::vector<double> > vw(indobs,indobs);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1287:54: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
 1287 |      std::vector< std::vector<double> > vwut(indobs,1);
      |                                                      ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
sgp4dc.cpp:1288:66: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
 1288 |      std::vector< std::vector<double> > atwao(statesize,statesize);
      |                                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
In file included from testdc.cpp:30:
sgp4dc.h:37:75: warning: extra tokens at end of #include directive
   37 | #include "astiod.h"                                                       `
      |                                                                           ^
testdc.cpp: In function ‘void func()’:
testdc.cpp:58:24: error: ‘_argc’ was not declared in this scope
   58 |    cout << "argc= " << _argc << endl;
      |                        ^~~~~
testdc.cpp:61:15: error: ‘_argv’ was not declared in this scope
   61 |       cout << _argv[i] << endl;
      |               ^~~~~
testdc.cpp:62:18: error: ‘_argv’ was not declared in this scope
   62 |    typeans    = *_argv[1];
      |                  ^~~~~
testdc.cpp: In function ‘void processrazel()’:
testdc.cpp:139:50: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  139 |      std::vector< std::vector<double> > trans(3,3);
      |                                                  ^
In file included from /usr/include/c++/13/vector:66,
                 from testdc.cpp:11:
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/13/bits/stl_algobase.h:65,
                 from /usr/include/c++/13/bits/specfun.h:43,
                 from /usr/include/c++/13/cmath:3699,
                 from /usr/include/c++/13/math.h:36,
                 from testdc.cpp:7:
/usr/include/c++/13/bits/stl_iterator_base_types.h: In substitution of ‘template<class _InIter> using std::_RequireInputIter = std::__enable_if_t<std::is_convertible<typename std::iterator_traits< <template-parameter-1-1> >::iterator_category, std::input_iterator_tag>::value> [with _InIter = int]’:
/usr/include/c++/13/bits/stl_vector.h:705:9:   required from here
/usr/include/c++/13/bits/stl_iterator_base_types.h:250:11: error: no type named ‘iterator_category’ in ‘struct std::iterator_traits<int>’
  250 |     using _RequireInputIter =
      |           ^~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:159:54: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  159 |      std::vector< std::vector<double> > x(statesize,1);
      |                                                      ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:160:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  160 |      std::vector< std::vector<double> > scalef(statesize,1);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:161:55: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  161 |      std::vector< std::vector<double> > dx(statesize,1);
      |                                                       ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:162:66: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  162 |      std::vector< std::vector<double> > atwai(statesize,statesize);
      |                                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:163:65: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  163 |      std::vector< std::vector<double> > atwa(statesize,statesize);
      |                                                                 ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:164:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  164 |      std::vector< std::vector<double> > atwb(statesize,1);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:257:52: warning: format ‘%d’ expects argument of type ‘int*’, but argument 4 has type ‘long int*’ [-Wformat=]
  257 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf ",
      |                                                   ~^
      |                                                    |
      |                                                    int*
      |                                                   %ld
  258 |                                      &currobsrec.obstype, &currobsrec.satnum, &currobsrec.sennum,
      |                                                           ~~~~~~~~~~~~~~~~~~
      |                                                           |
      |                                                           long int*
testdc.cpp:257:47: warning: too many arguments for format [-Wformat-extra-args]
  257 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf ",
      |                                               ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
testdc.cpp:266:52: warning: format ‘%d’ expects argument of type ‘int*’, but argument 4 has type ‘long int*’ [-Wformat=]
  266 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf %lf ",
      |                                                   ~^
      |                                                    |
      |                                                    int*
      |                                                   %ld
  267 |                                      &currobsrec.obstype, &currobsrec.satnum, &currobsrec.sennum,
      |                                                           ~~~~~~~~~~~~~~~~~~
      |                                                           |
      |                                                           long int*
testdc.cpp:266:47: warning: too many arguments for format [-Wformat-extra-args]
  266 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf %lf ",
      |                                               ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
testdc.cpp:277:52: warning: format ‘%d’ expects argument of type ‘int*’, but argument 4 has type ‘long int*’ [-Wformat=]
  277 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf %lf %lf %lf ",
      |                                                   ~^
      |                                                    |
      |                                                    int*
      |                                                   %ld
  278 |                                      &currobsrec.obstype, &currobsrec.satnum, &currobsrec.sennum,
      |                                                           ~~~~~~~~~~~~~~~~~~
      |                                                           |
      |                                                           long int*
testdc.cpp:288:52: warning: format ‘%d’ expects argument of type ‘int*’, but argument 4 has type ‘long int*’ [-Wformat=]
  288 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf %lf ",
      |                                                   ~^
      |                                                    |
      |                                                    int*
      |                                                   %ld
  289 |                                      &currobsrec.obstype, &currobsrec.satnum, &currobsrec.sennum,
      |                                                           ~~~~~~~~~~~~~~~~~~
      |                                                           |
      |                                                           long int*
testdc.cpp:288:47: warning: too many arguments for format [-Wformat-extra-args]
  288 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf %lf ",
      |                                               ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
testdc.cpp: In function ‘void processxyz()’:
testdc.cpp:574:50: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int, int)’
  574 |      std::vector< std::vector<double> > trans(3,3);
      |                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:588:54: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  588 |      std::vector< std::vector<double> > x(statesize,1);
      |                                                      ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:589:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  589 |      std::vector< std::vector<double> > scalef(statesize,1);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:590:55: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  590 |      std::vector< std::vector<double> > dx(statesize,1);
      |                                                       ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:591:66: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  591 |      std::vector< std::vector<double> > atwai(statesize,statesize);
      |                                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:592:65: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  592 |      std::vector< std::vector<double> > atwa(statesize,statesize);
      |                                                                 ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:593:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  593 |      std::vector< std::vector<double> > atwb(statesize,1);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:680:47: warning: format ‘%s’ expects argument of type ‘char*’, but argument 3 has type ‘char (*)[20]’ [-Wformat=]
  680 |                           sscanf(longstr1,"%12s %s ", &tmp, &units );
      |                                            ~~~^       ~~~~
      |                                               |       |
      |                                               char*   char (*)[20]
testdc.cpp:680:50: warning: format ‘%s’ expects argument of type ‘char*’, but argument 4 has type ‘char (*)[10]’ [-Wformat=]
  680 |                           sscanf(longstr1,"%12s %s ", &tmp, &units );
      |                                                 ~^          ~~~~~~
      |                                                  |          |
      |                                                  char*      char (*)[10]
testdc.cpp:689:46: warning: format ‘%s’ expects argument of type ‘char*’, but argument 3 has type ‘char (*)[20]’ [-Wformat=]
  689 |                          sscanf(longstr1,"%14s %i %4s %i %3i %1c %2i %1c %lf ",
      |                                           ~~~^
      |                                              |
      |                                              char*
  690 |                              &tmp, &currobsrec.day, &monstr, &currobsrec.year, &currobsrec.hr, &tmpc,
      |                              ~~~~             
      |                              |
      |                              char (*)[20]
testdc.cpp:689:53: warning: format ‘%s’ expects argument of type ‘char*’, but argument 5 has type ‘char (*)[3]’ [-Wformat=]
  689 |                          sscanf(longstr1,"%14s %i %4s %i %3i %1c %2i %1c %lf ",
      |                                                   ~~^
      |                                                     |
      |                                                     char*
  690 |                              &tmp, &currobsrec.day, &monstr, &currobsrec.year, &currobsrec.hr, &tmpc,
      |                                                     ~~~~~~~
      |                                                     |
      |                                                     char (*)[3]
testdc.cpp:702:51: warning: format ‘%s’ expects argument of type ‘char*’, but argument 3 has type ‘char (*)[20]’ [-Wformat=]
  702 |                               sscanf(longstr1,"%16s %s ", &tmp, &coords );
      |                                                ~~~^       ~~~~
      |                                                   |       |
      |                                                   char*   char (*)[20]
testdc.cpp:702:54: warning: format ‘%s’ expects argument of type ‘char*’, but argument 4 has type ‘char (*)[10]’ [-Wformat=]
  702 |                               sscanf(longstr1,"%16s %s ", &tmp, &coords );
      |                                                     ~^          ~~~~~~~
      |                                                      |          |
      |                                                      char*      char (*)[10]
testdc.cpp: In function ‘void processtle()’:
testdc.cpp:949:54: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  949 |      std::vector< std::vector<double> > x(statesize,1);
      |                                                      ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:950:59: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  950 |      std::vector< std::vector<double> > scalef(statesize,1);
      |                                                           ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:951:55: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  951 |      std::vector< std::vector<double> > dx(statesize,1);
      |                                                       ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:952:66: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  952 |      std::vector< std::vector<double> > atwai(statesize,statesize);
      |                                                                  ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:953:65: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int&)’
  953 |      std::vector< std::vector<double> > atwa(statesize,statesize);
      |                                                                 ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:954:57: error: no matching function for call to ‘std::vector<std::vector<double> >::vector(int&, int)’
  954 |      std::vector< std::vector<double> > atwb(statesize,1);
      |                                                         ^
/usr/include/c++/13/bits/stl_vector.h:707:9: note: candidate: ‘template<class _InputIterator, class> std::vector<_Tp, _Alloc>::vector(_InputIterator, _InputIterator, const allocator_type&) [with <template-parameter-2-2> = _InputIterator; _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  707 |         vector(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:707:9: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_vector.h:678:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::initializer_list<_Tp>, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  678 |       vector(initializer_list<value_type> __l,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:678:43: note:   no known conversion for argument 1 from ‘int’ to ‘std::initializer_list<std::vector<double> >’
  678 |       vector(initializer_list<value_type> __l,
      |              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:659:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:659:23: note:   no known conversion for argument 1 from ‘int’ to ‘std::vector<std::vector<double> >&&’
  659 |       vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
      |              ~~~~~~~~~^~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::false_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::false_type = std::integral_constant<bool, false>]’
  640 |       vector(vector&& __rv, const allocator_type& __m, false_type)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:640:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:635:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&, const allocator_type&, std::true_type) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >; std::true_type = std::integral_constant<bool, true>]’
  635 |       vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:635:7: note:   candidate expects 3 arguments, 2 provided
/usr/include/c++/13/bits/stl_vector.h:624:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&, std::__type_identity_t<_Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; std::__type_identity_t<_Alloc> = std::allocator<std::vector<double> >]’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:624:28: note:   no known conversion for argument 1 from ‘int’ to ‘const std::vector<std::vector<double> >&’
  624 |       vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
      |              ~~~~~~~~~~~~~~^~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  620 |       vector(vector&&) noexcept = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:620:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:601:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  601 |       vector(const vector& __x)
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:601:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:569:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const value_type&, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; value_type = std::vector<double>; allocator_type = std::allocator<std::vector<double> >]’
  569 |       vector(size_type __n, const value_type& __value,
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:569:47: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::value_type&’ {aka ‘const std::vector<double>&’}
  569 |       vector(size_type __n, const value_type& __value,
      |                             ~~~~~~~~~~~~~~~~~~^~~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(size_type, const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; size_type = long unsigned int; allocator_type = std::allocator<std::vector<double> >]’
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:556:51: note:   no known conversion for argument 2 from ‘int’ to ‘const std::vector<std::vector<double> >::allocator_type&’ {aka ‘const std::allocator<std::vector<double> >&’}
  556 |       vector(size_type __n, const allocator_type& __a = allocator_type())
      |                             ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector(const allocator_type&) [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >; allocator_type = std::allocator<std::vector<double> >]’
  542 |       vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:542:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_vector.h:531:7: note: candidate: ‘std::vector<_Tp, _Alloc>::vector() [with _Tp = std::vector<double>; _Alloc = std::allocator<std::vector<double> >]’
  531 |       vector() = default;
      |       ^~~~~~
/usr/include/c++/13/bits/stl_vector.h:531:7: note:   candidate expects 0 arguments, 2 provided
testdc.cpp:1163:37: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long int’ [-Wformat=]
 1163 |                fprintf(outfile1," %8d  difference %11lf  %11lf  %11lf km %12lf m \n\n",satrec.satnum, dr[0], dr[1], dr[2], 1000.0 * mag(dr) );
      |                                   ~~^                                                  ~~~~~~~~~~~~~
      |                                     |                                                         |
      |                                     int                                                       long int
      |                                   %8ld
testdc.cpp:1170:45: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
 1170 |                    fprintf(outfile2," %4i %8d %12.0lf %14.6lf %10.2lf %12lf %8.4lf %7.0lf %7.0lf %10.2lf\n",
      |                                           ~~^
      |                                             |
      |                                             int
      |                                           %8ld
 1171 |                            loops, satrec.satnum, magdr1, 0.000001, satrecx.a*6378, satrecx.ecco, satrecx.inclo*rad, apalt, pralt, magcov );
      |                                   ~~~~~~~~~~~~~
      |                                          |
      |                                          long int
testdc.cpp:1173:45: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long int’ [-Wformat=]
 1173 |                    fprintf(outfile2," %4i %8d %12.0lf %14.6lf %10.2lf %12lf %8.4lf %7.0lf %7.0lf %10.2lf\n",
      |                                           ~~^
      |                                             |
      |                                             int
      |                                           %8ld
 1174 |                            loops, satrec.satnum, magdr1, 1000.0 * mag(dr), satrecx.a*6378, satrecx.ecco, satrecx.inclo*rad, apalt, pralt, magcov );
      |                                   ~~~~~~~~~~~~~
      |                                          |
      |                                          long int
