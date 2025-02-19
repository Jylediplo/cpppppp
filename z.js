 var e = function() {
	for (var e, n, t, a, c, r, i, o = [], u = 0; u < 256; u++) o[u] = new Array(999);
	for (var s = 0; s < 999; s++)
	  for (var f = 0; f < 256; f++) o[f][s] = o[(e = s, n = f, t = 119, a = 256, c = 433, r = 911, i = 313, (e * c ^ n * r ^ t * i) >>> 0 & a - 1)];
	return o[119]
  }();
  function n(e, n) {
	return 1 * (e & n) + 11 * (e & ~n) - 11 * (e | ~n) + 11 * ~(e ^ n) + 1 * ~(e | ~n)
  }
  function t(e, n) {
	var t = ~n;
	return 2 * (e & n) + 8 * (e & t) - 7 * (e ^ n) - 1 * e + 8 * ~(e | t)
  }

  function a(e, n) {
	var t = e | n;
	return 5 * (e & n) + 2 * (e & ~n) - 2 * t - 2 * ~(e ^ n) + 2 * ~t + 3 * ~(e | ~n)
  }

  function c(e, n) {
	var t = ~n;
	return 1 * (e & n) + 1 * (e & t) - 1 * ~(e & n) - 3 * ~(e | n) - 2 * ~(e | t) + 4 * ~e
  }

  function r(e, n) {
	return 3 * (e & n) + 1 * (e & ~n) - 1 * (e | ~n) - 1 * n + 1 * ~(e | n) + 2 * ~(e | ~n)
  }

  function i(e, n) {
	return -1 * (e & n) + 2 * ~(e ^ n) - 9 * ~(e | n) - 6 * ~(e | ~n) + 7 * ~e
  }

  function o(e, n) {
	return 1 * (e & n) + 6 * (e & ~n) - 5 * ~(e & n) + 4 * ~(e | n) + 4 * ~(e | ~n) + 1 * ~e
  }

  function u(e, n) {
	return -3 * (e & n) + 8 * (e & ~n) - 7 * (e | ~n) + 11 * ~(e ^ n) - 4 * ~(e | n)
  }

  function s(e, n) {
	return -1 * (e & n) + 1 * (e & ~n) - 2 * (e ^ n) + 2 * (e | n)
  }

  function f(e, n) {
	var t = e | n;
	return -4 * (e & n) + 1 * t + 4 * ~(e & ~n) - 4 * ~t - 5 * ~(e | ~n)
  }

  function v(e, n) {
	return -11 * (e & n) - 10 * (e & ~n) + 11 * (e | n) + 1 * ~(e & ~n) - 1 * ~(e | n) - 12 * ~(e | ~n)
  }

  function h(e, n) {
	return 3 * (e & n) + 3 * (e & ~n) - 6 * (e | ~n) + 4 * e + 6 * ~(e | n)
  }

  function g(e, n) {
	var t = ~n;
	return 3 * (e & n) + 1 * (e & ~n) - 2 * n - 1 * ~(e & t) + 1 * ~(e | n) + 2 * ~(e | t)
  }

  function l(e, n) {
	var t = ~n;
	return -3 * (e & ~n) + 7 * ~(e | n) + 10 * ~(e | t) - 11 * ~e + 4 * t
  }

  function w(e, n) {
	var t = e | n;
	return 7 * (e & n) + 8 * (e & ~n) - 7 * t - 11 * ~t - 5 * ~(e | ~n) + 11 * ~e
  }

  function d(e, n) {
	var t = ~n;
	return -2 * (e & n) - 1 * (e & t) + 2 * e - 1 * ~(e | n) - 2 * ~(e | t) + 1 * ~e
  }

  function b(e, n) {
	var t = ~n;
	return -7 * (e & n) + 3 * (e & t) - 2 * ~(e & n) + 7 * ~(e & t) - 5 * ~(e | n) - 6 * ~(e | t)
  }

  function p(e, n) {
	return 10 * (e & n) + 12 * (e & ~n) - 11 * e + 1 * (e ^ ~n) - 1 * ~(e | n) - 1 * ~(e | ~n)
  }

  function y(e, n) {
	var t = e & n,
	  a = ~n;
	return 8 * t + 2 * (e & a) - 6 * n - 1 * ~t + 1 * ~(e | n) + 8 * ~(e | a)
  }

  function m(e, n) {
	var t = ~n;
	return -5 * (e & n) - 1 * (e & t) + 2 * (e | t) + 5 * ~(e & ~n) - 7 * ~(e | n) - 4 * ~(e | ~n)
  }

  function x(e, n) {
	return -1 * (e & n) + 3 * n + 1 * ~(e & n) - 1 * ~(e | n) - 3 * ~(e | ~n)
  }

  function N(e, n) {
	var t = ~n;
	return 1 * (e & n) + 1 * (e & t) + 1 * ~(e & ~n) + 1 * ~(e | t) - 1 * ~e
  }

  function k(e, n) {
	var t = ~n;
	return 4 * (e & n) + 3 * (e & t) - 2 * e - 11 * ~(e | n) - 10 * ~(e | t) + 11 * ~e
  }

  function C(e, n) {
	return 2 * (e & n) + 8 * (e & ~n) - 5 * (e ^ n) + 2 * ~(e | n) + 6 * ~(e | ~n) - 2 * ~n
  }
