type t;

/* Arithmetic */
let add: (t, t) => t;

let addn: (float, t) => t;

let iadd: (t, t) => t;

let iaddn: (float, t) => t;

let sub: (t, t) => t;

let subn: (float, t) => t;

let isub: (t, t) => t;

let isubn: (float, t) => t;

let cmp: (t, t) => Equality.t;

let neg: t => t;

/* Export */
let toString: (~base: int=?, t) => string;

let toArray: (~endian: Endianness.t=?, ~length: int=?, t) => array(int);

/* Import */
let fromFloat: (~base: int=?, ~endian: Endianness.t=?, float) => t;

let fromString: (~base: int=?, ~endian: Endianness.t=?, string) => t;

let fromArray: (~base: int=?, ~endian: Endianness.t=?, array(int)) => t;

let fromBuffer: (~base: int=?, ~endian: Endianness.t=?, Node.Buffer.t) => t;

let clone: t => t;