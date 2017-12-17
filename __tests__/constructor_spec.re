open Jest;

open BnRe;

let _ =
  describe(
    "from float",
    ExpectJs.(
      () => {
        test(
          "one limb number",
          () => expect(Bn.fromFloat(12345.) |> Bn.toStringWithBase(16)) |> toBe("3039")
        );
        test(
          "two-limb number",
          () =>
            expect(Bn.fromFloat(float_of_int(0x4123456)) |> Bn.toStringWithBase(16))
            |> toBe("4123456")
        );
        test(
          "accepts 52 bits of precision",
          () =>
            expect(
              Bn.fromFloatWithBase(Js.Math.pow_float(~base=2., ~exp=52.), 10)
              |> Bn.toStringWithBase(10)
            )
            |> toBe("4503599627370496")
        );
        test(
          "accepts max safe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.) -. 1.;
            expect(Bn.fromFloatWithBase(num, 10) |> Bn.toStringWithBase(10))
            |> toBe("9007199254740991")
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
            expect(
              Bn.fromFloatWithEndianness(float_of_int(0x4123456), `le) |> Bn.toStringWithBase(16)
            )
            |> toBe("56341204")
        )
      }
    )
  );

let _ =
  describe(
    "from string",
    ExpectJs.(
      () => {
        test(
          "accepts base-16",
          () =>
            expect(Bn.fromStringWithBase("1A6B765D8CDF", 16) |> Bn.toStringWithBase(16))
            |> toBe("1a6b765d8cdf")
        );
        test(
          "accepts base-16 ex 2",
          () =>
            expect(Bn.fromStringWithBase("1A6B765D8CDF", 16) |> Bn.toString())
            |> toBe("29048849665247")
        );
        test(
          "accepts no base",
          () =>
            expect(Bn.fromString("10000000000000000") |> Bn.toString())
            |> toBe("10000000000000000")
        );
        test(
          "accepts base-36",
          () => {
            let base36 = "zzZzzzZzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            expect(Bn.fromStringWithBase(base36, 36) |> Bn.toStringWithBase(36))
            |> toBe(String.lowercase(base36))
          }
        );
        test(
          "accepts base-16 LE integer",
          () => {
            expect(Bn.fromStringWithBaseAndEndianness("1A6B765D8CDF", 16, `le) |> Bn.toStringWithBase(16))
            |> toBe("df8c5d766b1a")
          }
        );
      }
    )
  );
