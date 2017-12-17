open Jest;

let _ =
  describe(
    "from float",
    ExpectJs.(
      () => {
        test(
          "one limb number",
          () => expect(Bn.fromFloat(12345.) |> Bn.toString(~base=16)) |> toBe("3039")
        );
        test(
          "two-limb number",
          () =>
            expect(Bn.fromFloat(float_of_int(0x4123456)) |> Bn.toString(~base=16))
            |> toBe("4123456")
        );
        test(
          "accepts 52 bits of precision",
          () =>
            expect(
              Bn.fromFloat(~base=10, Js.Math.pow_float(~base=2., ~exp=52.)) |> Bn.toString(~base=10)
            )
            |> toBe("4503599627370496")
        );
        test(
          "accepts max safe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.) -. 1.;
            expect(Bn.fromFloat(~base=10, num) |> Bn.toString(~base=10)) |> toBe("9007199254740991")
          }
        );
        test(
          "does not accept unsafe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.);
            expect(() => Bn.fromFloat(~base=10, num)) |> toThrow
          }
        );
        test(
          "accepts two-limb LE number",
          () =>
            expect(Bn.fromFloat(~endianness=`le, float_of_int(0x4123456)) |> Bn.toString(~base=16))
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
            expect(Bn.fromString(~base=16, "1A6B765D8CDF") |> Bn.toString(~base=16))
            |> toBe("1a6b765d8cdf")
        );
        test(
          "accepts base-16 ex 2",
          () =>
            expect(Bn.fromString(~base=16, "1A6B765D8CDF") |> Bn.toString) |> toBe("29048849665247")
        );
        test(
          "accepts no base",
          () =>
            expect(Bn.fromString("10000000000000000") |> Bn.toString) |> toBe("10000000000000000")
        );
        test(
          "accepts base-36",
          () => {
            let base36 = "zzZzzzZzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            expect(Bn.fromString(~base=36, base36) |> Bn.toString(~base=36))
            |> toBe(String.lowercase(base36))
          }
        );
        test(
          "accepts base-16 LE integer",
          () =>
            expect(
              Bn.fromString(~base=16, ~endianness=`le, "1A6B765D8CDF") |> Bn.toString(~base=16)
            )
            |> toBe("df8c5d766b1a")
        )
      }
    )
  );
