type t;

/* Arithmetic */
let add: (t, t) => t;

let addn: (float, t) => t;

let iadd: (t, t) => unit;

let iaddn: (float, t) => unit;

let sub: (t, t) => t;

let subn: (float, t) => t;

let isub: (t, t) => unit;

let isubn: (float, t) => unit;

let mul: (t, t) => t;

let mulf: (t, t) => t;

let imul: (t, t) => unit;

let imuln: (float, t) => unit;

let muln: (float, t) => t;

let sqr: t => t;

let isqr: t => unit;

let pow: (t, t) => t;

let div: (t, t) => t;

let mod_: (t, t) => t;

let umod: (t, t) => t;

let divRound: (t, t) => t;

let modrn: (float, t) => t;

let idivn: (float, t) => unit;

let divn: (float, t) => t;

let cmp: (t, t) => Equality.t;

let neg: t => t;

let isNeg: t => bool;

let iushln: (int, t) => unit;

let ishln: (int, t) => unit;

let iushrn: (int, t) => unit;

let ishrn: (int, t) => unit;

let shln: (int, t) => t;

let ushln: (int, t) => t;

let shrn: (int, t) => t;

let ushrn: (int, t) => t;

/* Export */
let toString: (~base: int=?, t) => string;

let toArray: (~endian: Endianness.t=?, ~length: int=?, t) => array(int);

/* Import */
let fromFloat: (~base: int=?, ~endian: Endianness.t=?, float) => t;

let fromString: (~base: int=?, ~endian: Endianness.t=?, string) => t;

let fromArray: (~base: int=?, ~endian: Endianness.t=?, array(int)) => t;

let fromBuffer: (~base: int=?, ~endian: Endianness.t=?, Node.Buffer.t) => t;

let clone: t => t;

/* Utils */
let copy: (t, t) => unit;

let inspect: t => string;