type t;

[@bs.deriving {jsConverter: newType}]
type egcd_t = {
  a: t,
  b: t,
  gcd: t
};

/* Arithmetic */
/** Returns the addition of two big numbers. */
let add: (t, t) => t;

/** Returns the addition of a float and a big number. */
let addn: (float, t) => t;

/** Adds a big number to another, storing the result in the second (side effect). */
let iadd: (t, t) => unit;

/** Adds a float to a big number, storing the result in the second (side effect). */
let iaddn: (float, t) => unit;

/** Returns the subtraction of two big numbers (the second minus the first). */
let sub: (t, t) => t;

/** Returns the subtraction of a float from a big number. */
let subn: (float, t) => t;

/** Subtracts a big number from another, storing the result in the second (side effect). */
let isub: (t, t) => unit;

/** Subtracts a float from a big number, storing the result in the second (side effect). */
let isubn: (float, t) => unit;

/** Returns the absolute value. */
let abs: t => t;

/** Calculates the absolute value and stores it in the big number passed as param (side effect). */
let iabs: t => unit;

/** Returns the multiplication of two big numbers. */
let mul: (t, t) => t;

/** Returns the multiplication of two big numbers, using FFT. */
let mulf: (t, t) => t;

/** Multiplies a big number with another, storing the result in the second (side effect). */
let imul: (t, t) => unit;

/** Multiplies a float with a big number, storing the result in the second (side effect). */
let imuln: (float, t) => unit;

/** Returns the multiplication of a float with a big number. */
let muln: (float, t) => t;

/** Returns the square root of a big number. */
let sqr: t => t;

/** Calculates the square root of a big number and stores it in the big number passed as param (side effect). */
let isqr: t => unit;

/** Returns the power considering the first param as exponent and the second as base. */
let pow: (t, t) => t;

/** Returns the quotient after dividing two big numbers. The first param is the divisor and the second is the divident: div(a, b) is equivalent to b / a. */
let div: (t, t) => t;

/** Returns the remainder after dividing two big numbers. The first param is the divisor and the second is the divident: mod_(a, b) is equivalent to b % a. */
let mod_: (t, t) => t;

/** Returns the unsigned remainder after dividing two big numbers. The first param is the divisor and the second is the divident: umod(a, b) is equivalent to b % a. */
let umod: (t, t) => t;

/** Returns the rounded quotient after dividing two big numbers. The first param is the divisor and the second is the divident: divRound(a, b) is equivalent to Math.round(b / a). */
let divRound: (t, t) => t;

/** Returns the remainder after dividing a big number by a float. The first param is the divisor and the second is the divident: modn(a, b) is equivalent to b % a. */
let modn: (float, t) => t;

/** Calculates the quotient after dividing a big number by a float, storing the result in the big number (side effect). The first param is the divisor and the second is the divident: idivn(a, b) is equivalent to b / a. */
let idivn: (float, t) => unit;

/** Returns the quotient after dividing a big number by a float. The first param is the divisor and the second is the divident: divn(a, b) is equivalent to b / a. */
let divn: (float, t) => t;

/** Compares two big numbers and returns the results of the comparison (equal, less than, greater). */
let cmp: (t, t) => Equality.t;

/** Compares a float with a big number and returns the results of the comparison (equal, less than, greater). */
let cmpn: (float, t) => Equality.t;

/** Returns the negative version of a big number. */
let neg: t => t;

/** Calculates the negative version of a big number, storing the result in that same reference (side effect). */
let ineg: t => unit;

/** Returns true if the big number is negative. */
let isNeg: t => bool;

/** Returns the inverted value of the second param, modulo the first param. */
let invm: (t, t) => t;

/** Returns the greater common divisor of two big numbers. */
let gcd: (t, t) => t;

/** Returns the results of the extended greater common divisor ax + by = gcd(a, b). The result is a record with shape: { a: ..., b: ..., gcd: ... } */
let egcd: (t, t) => egcd_t;

/** Unsigned shift left n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let iushln: (int, t) => unit;

/** Shift left n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let ishln: (int, t) => unit;

/** Unsigned shift right n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let iushrn: (int, t) => unit;

/** Shift right n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let ishrn: (int, t) => unit;

/** Returns the result of shifting left n bits (first param) a big number (second param). */
let shln: (int, t) => t;

/** Returns the result of unsigned shifting left n bits (first param) a big number (second param). */
let ushln: (int, t) => t;

/** Returns the result of shifting right n bits (first param) a big number (second param). */
let shrn: (int, t) => t;

/** Returns the result of unsigned shifting right n bits (first param) a big number (second param). */
let ushrn: (int, t) => t;

/** Returns the max of two big numbers. */
let max: (t, t) => t;

/** Returns the min of two big numbers. */
let min: (t, t) => t;

/* Export */
/** Returns a big number represented as a number. */
let toNumber: t => float;

/** Returns a big number represented as a string. */
let toString: (~base: int=?, t) => string;

/** Returns a big number represented as an array. */
let toArray: (~endian: Endianness.t=?, ~length: int=?, t) => array(int);

/* Import */
/** Creates a big number from a float. */
let fromFloat: (~base: int=?, ~endian: Endianness.t=?, float) => t;

/** Creates a big number from a string. */
let fromString: (~base: int=?, ~endian: Endianness.t=?, string) => t;

/** Creates a big number from an array. */
let fromArray: (~base: int=?, ~endian: Endianness.t=?, array(int)) => t;

/** Creates a big number from a Buffer. */
let fromBuffer: (~base: int=?, ~endian: Endianness.t=?, Node.Buffer.t) => t;

/** Returns a new copy of a big number. */
let clone: t => t;

/* Utils */
/** Copies the big number passed as first param into the big number passed as second param (side effect). */
let copy: (t, t) => unit;

/** For debugging purposes: prints a big number as a string (including structural information). */
let inspect: t => string;