type t;

module Impl = (Bn: {type t;}) => {
  [@bs.module "bn.js"] external red : Bn.t => t = "";
  [@bs.module "bn.js"] external mont : Bn.t => t = "";
  [@bs.send] external fromRed : t => Bn.t = "";
  [@bs.send.pipe : t] external redAdd : t => t = "";
  [@bs.send.pipe : t] external redSub : t => t = "";
  [@bs.send.pipe : t] external redIAdd : t => unit = "";
  [@bs.send.pipe : t] external redISub : t => unit = "";
  [@bs.send] external cloneRed : t => t = "clone";
};
