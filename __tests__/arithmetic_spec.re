open Jest;

let _ =
  describe(
    "add",
    ExpectJs.(
      () => {
        test(
          "adds numbers",
          () =>
            expect(Bn.fromFloat(14.) |> Bn.add(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
            |> toBe("28")
        );
        test(
          "adds numbers case 2",
          () => {
            let k = Bn.fromFloat(float_of_int(0x1234));
            let r = ref(k);
            for (_ in 0 to 256) {
              r := Bn.add(k, r^)
            };
            expect(Bn.toString(~base=16, r^)) |> toBe("125868")
          }
        );
        test(
          "handles carry properly (in-place)",
          () => {
            let k = Bn.fromString(~base=16, "abcdefabcdefabcdef");
            let r = ref(Bn.fromString(~base=16, "deadbeef"));
            for (_ in 0 to 256) {
              r := Bn.iadd(k, r^)
            };
            expect(Bn.toString(~base=16, r^)) |> toBe("ac79bd9b79be7a277bde")
          }
        );
        test(
          "does positive + negative",
          () => {
            let a = Bn.fromString(~base=16, "abcd");
            let b = Bn.fromString(~base=16, "-abce");
            expect(Bn.iadd(a, b) |> Bn.toString(~base=16)) |> toBe("-1")
          }
        )
      }
    )
  );

let _ =
  describe(
    "iaddn",
    ExpectJs.(
      () => {
        test(
          "allows a sign change",
          () => {
            let a = Bn.fromFloat((-100.));
            expect(Bn.iaddn(200., a) |> Bn.toString) |> toBe("100")
          }
        );
        test(
          "adds a negative number",
          () => {
            let a = Bn.fromFloat((-100.));
            expect(Bn.iaddn((-200.), a) |> Bn.toString) |> toBe("-300")
          }
        );
        test(
          "allows neg + pos with big number",
          () => {
            let a = Bn.fromFloat(~base=10, (-1000000000.));
            expect(Bn.iaddn(200., a) |> Bn.toString) |> toBe("-999999800")
          }
        );
        test(
          "carries limb",
          () => {
            let a = Bn.fromString(~base=16, "3ffffff");
            expect(Bn.iaddn(1., a) |> Bn.toString(~base=16)) |> toBe("4000000")
          }
        );
        test(
          "throws error with num eq 0x4000000",
          () => expect(() => Bn.fromFloat(0.) |> Bn.iaddn(float_of_int(0x4000000))) |> toThrow
        )
      }
    )
  );
