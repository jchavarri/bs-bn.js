module Bn = {
  type t;
  [@bs.send.pipe : t] external toStringWithBase : int => string = "toString";
  [@bs.send.pipe : t] external toString : unit => string = "";
};

/* From float */
[@bs.module "bn.js"] [@bs.new] external numberFromFloat : float => Bn.t = "BN";

[@bs.module "bn.js"] [@bs.new] external numberFromFloatWithBase : (float, int) => Bn.t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithEndianness : (float, [@bs.string] [ | `le | `be]) => Bn.t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithBaseAndEndianness : (float, int, [@bs.string] [ | `le | `be]) => Bn.t =
  "BN";

let fromFloat = (~base=?, ~endianness=?, v) =>
  switch (base, endianness) {
  | (Some(b), Some(e)) => numberFromFloatWithBaseAndEndianness(v, b, e)
  | (Some(b), None) => numberFromFloatWithBase(v, b)
  | (None, Some(e)) => numberFromFloatWithEndianness(v, e)
  | (None, None) => numberFromFloat(v)
  };

/* From string */
[@bs.module "bn.js"] [@bs.new] external numberFromString : string => Bn.t = "BN";

[@bs.module "bn.js"] [@bs.new] external numberFromStringWithBase : (string, int) => Bn.t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithEndianness : (string, [@bs.string] [ | `le | `be]) => Bn.t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithBaseAndEndianness : (string, int, [@bs.string] [ | `le | `be]) => Bn.t =
  "BN";

let fromString = (~base=?, ~endianness=?, v) =>
  switch (base, endianness) {
  | (Some(b), Some(e)) => numberFromStringWithBaseAndEndianness(v, b, e)
  | (Some(b), None) => numberFromStringWithBase(v, b)
  | (None, Some(e)) => numberFromStringWithEndianness(v, e)
  | (None, None) => numberFromString(v)
  };