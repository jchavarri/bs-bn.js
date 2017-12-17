module Bn = {
  type t;
  [@bs.send.pipe : t] external toString : int => string = "";
};

[@bs.module "bn.js"][@bs.new] external bigNum : int => Bn.t = "BN";
