module Bn = {
  type t;
  [@bs.module "bn.js"] [@bs.new] external fromFloat : float => t = "BN";
  [@bs.module "bn.js"] [@bs.new] external fromFloatWithBase : (float, int) => t = "BN";
  [@bs.module "bn.js"] [@bs.new]
  external fromFloatWithEndianness : (float, [@bs.string] [ | `le | `be]) => t =
    "BN";
  [@bs.module "bn.js"] [@bs.new] external fromString : string => t = "BN";
  [@bs.module "bn.js"] [@bs.new] external fromStringWithBase : (string, int) => t = "BN";
  [@bs.module "bn.js"] [@bs.new]
  external fromStringWithEndianness : (string, [@bs.string] [ | `le | `be]) => t =
    "BN";
  [@bs.module "bn.js"] [@bs.new]
  external fromStringWithBaseAndEndianness : (string, int, [@bs.string] [ | `le | `be]) => t =
    "BN";
  [@bs.send.pipe : t] external toStringWithBase : int => string = "toString";
  [@bs.send.pipe : t] external toString : unit => string = "";
};