type t;
let toString: (~base: int=?, t) => string;
let toArray: (~endian: Endianness.t=?, ~length: int=?, t) => array(int);
let fromFloat: (~base: int=?, ~endian: Endianness.t=?, float) => t;
let fromString: (~base: int=?, ~endian: Endianness.t=?, string) => t;
let fromArray: (~base: int=?, ~endian: Endianness.t=?, array(int)) => t;