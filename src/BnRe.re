module Bn = {
  type t;
  [@bs.module "bn.js"] [@bs.new] external fromFloat : float => t = "BN";
  [@bs.module "bn.js"] [@bs.new] external fromFloatWithBase : (float, int) => t = "BN";
  [@bs.module "bn.js"] [@bs.new]
  external fromFloatWithEndianness : (float, [@bs.string] [ | `le | `be]) => t =
    "BN";
  [@bs.send.pipe : t] external toString : int => string = "";
};