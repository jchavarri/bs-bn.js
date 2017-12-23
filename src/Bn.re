type t;

/* ---- Arithmetic ---- */
/* Add */
[@bs.send.pipe : t] external add : t => t = "";

[@bs.send.pipe : t] external addn : float => t = "";

[@bs.send.pipe : t] external iadd : t => unit = "";

[@bs.send.pipe : t] external iaddn : float => unit = "";

[@bs.send.pipe : t] external sub : t => t = "";

[@bs.send.pipe : t] external subn : float => t = "";

[@bs.send.pipe : t] external isub : t => unit = "";

[@bs.send.pipe : t] external isubn : float => unit = "";

[@bs.send.pipe : t] external mul : t => t = "";

[@bs.send.pipe : t] external mulf : t => t = "";

[@bs.send.pipe : t] external imul : t => unit = "";

[@bs.send.pipe : t] external imuln : float => unit = "";

[@bs.send.pipe : t] external muln : float => t = "";

[@bs.send] external sqr : t => t = "";

[@bs.send] external isqr : t => unit = "";

[@bs.send.pipe : t] external pow : t => t = "";

[@bs.send.pipe : t] external div : t => t = "";

[@bs.send.pipe : t] external mod_ : t => t = "mod";

[@bs.send.pipe : t] external umod : t => t = "";

[@bs.send.pipe : t] external divRound : t => t = "";

[@bs.send.pipe : t] external modrn : float => t = "";

[@bs.send.pipe : t] external idivn : float => unit = "";

[@bs.send.pipe : t] external divn : float => t = "";

[@bs.send.pipe : t] external cmp : t => Equality.abs_t = "";

let cmp = (a, b) => Equality.tFromJs(cmp(a, b));

[@bs.send.pipe : t] external cmpn : float => Equality.abs_t = "";

let cmpn = (a, b) => Equality.tFromJs(cmpn(a, b));

[@bs.send.pipe : t] external iushln : int => unit = "";

[@bs.send.pipe : t] external ishln : int => unit = "";

[@bs.send.pipe : t] external iushrn : int => unit = "";

[@bs.send.pipe : t] external ishrn : int => unit = "";

[@bs.send.pipe : t] external shln : int => t = "";

[@bs.send.pipe : t] external ushln : int => t = "";

[@bs.send.pipe : t] external shrn : int => t = "";

[@bs.send.pipe : t] external ushrn : int => t = "";

[@bs.send] external neg : t => t = "";

[@bs.send] external isNeg : t => bool = "";

/* ---- Export ---- */
/* To string */
[@bs.send] external toNumber : t => float = "";

[@bs.send.pipe : t] external toStringWithBase : int => string = "toString";

[@bs.send.pipe : t] external toStringDefault : unit => string = "toString";

let toString = (~base=?) =>
  switch base {
  | Some(b) => toStringWithBase(b)
  | None => toStringDefault()
  };

/* To array */
[@bs.send.pipe : t]
external toArrayWithEndian : Endianness.abs_t => array(int) = "toArray";

[@bs.send.pipe : t] external toArrayWithLength : int => array(int) = "toArray";

[@bs.send.pipe : t]
external toArrayWithEndianAndLength : (Endianness.abs_t, int) => array(int) =
  "toArray";

[@bs.send.pipe : t] external toArrayDefault : unit => array(int) = "toArray";

let toArray = (~endian=?, ~length=?) =>
  switch (endian, length) {
  | (Some(e), Some(l)) => toArrayWithEndianAndLength(Endianness.tToJs(e), l)
  | (Some(e), None) => toArrayWithEndian(Endianness.tToJs(e))
  | (None, Some(l)) => toArrayWithLength(l)
  | (None, None) => toArrayDefault()
  };

/* ---- Creation ---- */
/* From float */
[@bs.module "bn.js"] [@bs.new] external numberFromFloat : float => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithBase : (float, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithEndianness : (float, Endianness.abs_t) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithBaseAndEndianness :
  (float, int, Endianness.abs_t) => t =
  "BN";

let fromFloat = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromFloatWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromFloatWithBase(v, b)
  | (None, Some(e)) => numberFromFloatWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromFloat(v)
  };

/* From string */
[@bs.module "bn.js"] [@bs.new] external numberFromString : string => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithBase : (string, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithEndianness : (string, Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithBaseAndEndianness :
  (string, int, Endianness.abs_t) => t =
  "BN";

let fromString = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromStringWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromStringWithBase(v, b)
  | (None, Some(e)) => numberFromStringWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromString(v)
  };

/* From array */
[@bs.module "bn.js"] [@bs.new]
external numberFromArray : array(int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithBase : (array(int), int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithEndianness : (array(int), Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithBaseAndEndianness :
  (array(int), int, Endianness.abs_t) => t =
  "BN";

let fromArray = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromArrayWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromArrayWithBase(v, b)
  | (None, Some(e)) => numberFromArrayWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromArray(v)
  };

/* From buffer */
[@bs.module "bn.js"] [@bs.new]
external numberFromBuffer : Node.Buffer.t => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithBase : (Node.Buffer.t, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithEndianness :
  (Node.Buffer.t, Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithBaseAndEndianness :
  (Node.Buffer.t, int, Endianness.abs_t) => t =
  "BN";

let fromBuffer = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromBufferWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromBufferWithBase(v, b)
  | (None, Some(e)) => numberFromBufferWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromBuffer(v)
  };

/* Clone */
[@bs.module "bn.js"] [@bs.new] external clone : t => t = "BN";

/* Utils */
[@bs.module "bn.js"] [@bs.new] external copy : (t, t) => unit = "BN";

[@bs.module "bn.js"] [@bs.new] external inspect : t => string = "BN";