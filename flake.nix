{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable-small";
  outputs = { self, nixpkgs }: with nixpkgs.legacyPackages.x86_64-linux;{
    packages.x86_64-linux.default = stdenv.mkDerivation {
      name = "gperf2json";
      src = self;
      nativeBuildInputs = [ meson ninja pkg-config ];
      buildInputs = [ nlohmann_json ];
      mesonFlags = [
        "-Dgperf=${runCommand "gperf" {} ''
          mkdir -p $out
          tar -x --strip-components 1 -f ${gperf.src} -C $out
        ''}"
      ];
    };
  };
}
