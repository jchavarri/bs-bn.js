open Jest;

let _ =
  describe(
    "add",
    ExpectJs.(
      () => {
        test("adds numbers", () =>
          expect(
            Bn.fromFloat(14.)
            |> Bn.add(Bn.fromFloat(26.))
            |> Bn.toString(~base=16)
          )
          |> toBe("28")
        );
        test("adds numbers case 2", () => {
          let k = Bn.fromFloat(float_of_int(0x1234));
          let r = ref(k);
          for (_ in 0 to 256) {
            r := Bn.add(k, r^);
          };
          expect(Bn.toString(~base=16, r^)) |> toBe("125868");
        });
        test("handles carry properly (in-place)", () => {
          let k = Bn.fromString(~base=16, "abcdefabcdefabcdef");
          let r = Bn.fromString(~base=16, "deadbeef");
          for (_ in 0 to 256) {
            Bn.iadd(k, r);
          };
          expect(Bn.toString(~base=16, r)) |> toBe("ac79bd9b79be7a277bde");
        });
        test("does positive + negative", () => {
          let a = Bn.fromString(~base=16, "abcd");
          let b = Bn.fromString(~base=16, "-abce");
          Bn.iadd(a, b);
          expect(b |> Bn.toString(~base=16)) |> toBe("-1");
        });
      }
    )
  );

let _ =
  describe(
    "iaddn",
    ExpectJs.(
      () => {
        test("allows a sign change", () => {
          let a = Bn.fromFloat(-100.);
          Bn.iaddn(200., a);
          expect(a |> Bn.toString) |> toBe("100");
        });
        test("adds a negative number", () => {
          let a = Bn.fromFloat(-100.);
          Bn.iaddn(-200., a);
          expect(a |> Bn.toString) |> toBe("-300");
        });
        test("allows neg + pos with big number", () => {
          let a = Bn.fromFloat(~base=10, -1000000000.);
          Bn.iaddn(200., a);
          expect(a |> Bn.toString) |> toBe("-999999800");
        });
        test("carries limb", () => {
          let a = Bn.fromString(~base=16, "3ffffff");
          Bn.iaddn(1., a);
          expect(a |> Bn.toString(~base=16)) |> toBe("4000000");
        });
        test("throws error with num eq 0x4000000", () =>
          expect(() =>
            Bn.fromFloat(0.) |> Bn.iaddn(float_of_int(0x4000000))
          )
          |> toThrow
        );
      }
    )
  );

let _ =
  describe(
    "sub",
    ExpectJs.(
      () => {
        test("subtracts small numbers", () => {
          let a = Bn.fromFloat(26.);
          expect(a |> Bn.sub(Bn.fromFloat(14.)) |> Bn.toString(~base=16))
          |> toBe("c");
        });
        test("subtracts small numbers 2", () => {
          let a = Bn.fromFloat(14.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("-c");
        });
        test("subtracts small numbers 3", () => {
          let a = Bn.fromFloat(26.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("0");
        });
        test("subtracts small numbers 4", () => {
          let a = Bn.fromFloat(-26.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("-34");
        });
        let a =
          Bn.fromString(
            ~base=16,
            "31ff3c61db2db84b9823d320907a573f6ad37c437abe458b1802cda041d6384a7d8daef41395491e2"
          );
        let b =
          Bn.fromString(
            ~base=16,
            "6f0e4d9f1d6071c183677f601af9305721c91d31b0bbbae8fb790000"
          );
        let r =
          Bn.fromString(
            ~base=16,
            "31ff3c61db2db84b9823d3208989726578fd75276287cd9516533a9acfb9a6776281f34583ddb91e2"
          );
        test("subtracts big numbers", () =>
          expect(a |> Bn.sub(b) |> Bn.cmp(r)) |> toBe(Equality.Equal)
        );
        test("subtracts numbers in place", () => {
          let c = Bn.clone(b);
          Bn.isub(a, c);
          expect(c |> Bn.neg |> Bn.cmp(r)) |> toBe(Equality.Equal);
        });
        test("subtracts with carry", () => {
          let a = Bn.fromString(~base=16, "12345");
          let b = Bn.fromString(~base=16, "1000000000000");
          Bn.isub(b, a);
          expect(a |> Bn.toString(~base=16)) |> toBe("-fffffffedcbb");
        });
      }
    )
  );

let _ =
  describe(
    "isubn",
    ExpectJs.(
      () => {
        test("subtracts negative number", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b"
            );
          Bn.isubn(-1., a);
          expect(a |> Bn.toString(~base=16))
          |> toBe(
               "7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681c"
             );
        });
        test("works for positive numbers", () => {
          let a = Bn.fromFloat(-100.);
          Bn.isubn(200., a);
          expect(a |> Bn.toString) |> toBe("-300");
        });
        test("does not allow a sign change", () => {
          let a = Bn.fromFloat(-100.);
          Bn.isubn(-200., a);
          expect(a |> Bn.toString) |> toBe("100");
        });
        test("changes sign on small numbers at 0", () => {
          let a = Bn.fromFloat(0.);
          expect(a |> Bn.subn(2.) |> Bn.toString) |> toBe("-2");
        });
        test("changes sign on small numbers at 1", () => {
          let a = Bn.fromFloat(1.);
          expect(a |> Bn.subn(2.) |> Bn.toString) |> toBe("-1");
        });
        test("throws error with num eq 0x4000000", () => {
          let a = Bn.fromFloat(0.);
          expect(() =>
            Bn.isubn(float_of_int(0x4000000), a)
          ) |> toThrow;
        });
      }
    )
  );

let testMethod = (name, mul) =>
  describe(
    name,
    ExpectJs.(
      () => {
        let offsets = [
          (1, "smallMulTo"),
          (250, "comb10MulTo"),
          (1000, "bigMulTo"),
          (15000, "jumboMulTo")
        ];
        let mulTests = [
          (x => mul(x, x) |> Bn.isNeg, false),
          (x => mul(x, Bn.neg(x)) |> Bn.isNeg, true),
          (x => mul(Bn.neg(x), x) |> Bn.isNeg, true),
          (x => mul(Bn.neg(x), Bn.neg(x)) |> Bn.isNeg, false)
        ];
        List.iter2(
          ((offset, name), (mulTest, mulTestResult)) =>
            test(
              "multiplies numbers of different signs - " ++ name,
              () => {
                let a = Bn.fromFloat(1.);
                Bn.ishln(offset, a);
                expect(mulTest(a)) |> toBe(mulTestResult);
              }
            ),
          offsets,
          mulTests
        );
        test("multiplies with carry", () => {
          let n = Bn.fromFloat(float_of_int(0x1001));
          let r = ref(n);
          for (_ in 0 to 3) {
            r := Bn.mul(n, r^);
          };
          expect(r^ |> Bn.toString(~base=16)) |> toBe("100500a00a005001");
        });
        test("multiplies big numbers", () => {
          let n =
            Bn.fromString(
              ~base=16,
              "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"
            );
          expect(Bn.mul(n, n) |> Bn.toString(~base=16))
          |> toBe(
               "39e58a8055b6fb264b75ec8c646509784204ac15a8c24e05babc9729ab9"
               ++ "b055c3a9458e4ce3289560a38e08ba8175a9446ce14e608245ab3a9"
               ++ "978a8bd8acaa40"
             );
        });
        test("multiplies neg number on 0", () =>
          expect(
            Bn.mul(
              Bn.fromString("-100000000000"),
              Bn.fromString("3") |> Bn.div(Bn.fromString("4"))
            )
            |> Bn.toString(~base=16)
          )
          |> toBe("0")
        );
      }
    )
  );

testMethod("mul", Bn.mul);

testMethod("mulf", Bn.mulf);
