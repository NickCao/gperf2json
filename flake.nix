{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable-small";
  outputs = { self, nixpkgs }: with nixpkgs.legacyPackages.x86_64-linux;{
    devShells.x86_64-linux.default = mkShell {
      nativeBuildInputs = [ meson ninja clang-tools ];
    };
  };
}
