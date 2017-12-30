open Jest;

let testMethod = (name, fn) =>
  describe(
    name,
    ExpectJs.(
      () =>
        [
          ((a, b) => a |> Bn.redAdd(b), "97"),
          ((a, b) => a |> Bn.redSub(b), "149"),
          ((a, b) => b |> Bn.redSub(a), "108"),
          (
            (a, b) => {
              a |> Bn.redIAdd(b);
              a;
            },
            "97"
          ),
          (
            (a, b) => {
              a |> Bn.redISub(b);
              a;
            },
            "149"
          ),
          (
            (a, b) => {
              b |> Bn.redISub(a);
              b;
            },
            "108"
          )
        ]
        |> List.iter(((op, r)) =>
             test("supports add, iadd, sub, isub operations", () => {
               let p = Bn.fromFloat(257.);
               let m = fn(p);
               let a = Bn.fromFloat(123.) |> Bn.toRed(m);
               let b = Bn.fromFloat(231.) |> Bn.toRed(m);
               expect(op(a, b) |> Bn.fromRed |> Bn.toString) |> toBe(r);
             })
           )
    )
  );

testMethod("Plain", Bn.red);

testMethod("Montgomery", Bn.mont);
