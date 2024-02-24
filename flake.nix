{
  description = "general env";

  inputs = {
    nixpkgs.url = "nixpkgs";
    flake-utils.url = "flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }@inputs:
    flake-utils.lib.eachDefaultSystem
      (system:
      let
        pkgs = import nixpkgs { inherit system; };

        buildInputs = with pkgs; [ 
          coreutils gnumake ninja cmake
          dtc
        ];
        devInputs = with pkgs; [
          git cacert which
        ];
      in
        {
          legacyPackages = pkgs;
          devShell = pkgs.mkShell {
            buildInputs = buildInputs ++ devInputs;
          };
        }
      )
    // {
      inherit inputs;  # for easier introspection via nix repl
    };
}
