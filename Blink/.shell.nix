{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
	nativeBuildInputs = let
		avrpkgs = pkgs.pkgsCross.avr.buildPackages;
	in [
		pkgs.arduino
		pkgs.arduino-core-unwrapped

		avrpkgs.gcc
		avrpkgs.binutils
		avrpkgs.avrdude
	];

	shellHook = ''
		zsh
	'';
}

