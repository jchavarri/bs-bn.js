# Contributing

Clone the repo and `npm install`. You can run `npm run watch:jest` while developing.

The main interface file is `Bn.rei`. All types are imported from `Types.re` to avoid cyclic references between `Bn.t` and `Red.t`. 