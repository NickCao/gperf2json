{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable-small";
  outputs = { self, nixpkgs }: with nixpkgs.legacyPackages.x86_64-linux;{
    packages.x86_64-linux.default = stdenv.mkDerivation {
      name = "gperf2json";
      srcs = [ self gperf.src ];
      sourceRoot = "source";
      nativeBuildInputs = [ meson ninja pkg-config ];
      buildInputs = [ nlohmann_json ];
      mesonFlags = [
        "-Dgperf=../${gperf.name}"
      ];
    };
  };
}
