type t;
let toString: (~base: int=?, t) => string;
let fromFloat: (~base: int=?, ~endianness: Endianness.t=?, float) => t;
let fromString: (~base: int=?, ~endianness: Endianness.t=?, string) => t;