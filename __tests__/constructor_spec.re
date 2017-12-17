open Jest;

open BnRe;

let _ =
  describe(
    "from float",
    ExpectJs.(
      () => {
        test(
          "one limb number",
          () => expect(Bn.fromFloat(12345.) |> Bn.toString(16)) |> toBe("3039")
        );
        test(
          "two-limb number",
          () => expect(Bn.fromFloat(float_of_int(0x4123456)) |> Bn.toString(16)) |> toBe("4123456")
        );
        test(
          "accepts 52 bits of precision",
          () =>
            expect(
              Bn.fromFloatWithBase(Js.Math.pow_float(~base=2., ~exp=52.), 10) |> Bn.toString(10)
            )
            |> toBe("4503599627370496")
        );
        test(
          "accepts max safe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.) -. 1.;
            expect(Bn.fromFloatWithBase(num, 10) |> Bn.toString(10)) |> toBe("9007199254740991")
          }
        );
        test(
          "does not accept unsafe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.);
            expect(() => Bn.fromFloatWithBase(num, 10)) |> toThrow
          }
        );
        test(
          "accepts two-limb LE number",
          () =>
            expect(Bn.fromFloatWithEndianness(float_of_int(0x4123456), `le) |> Bn.toString(16))
            |> toBe("56341204")
        )
      }
    )
  );
