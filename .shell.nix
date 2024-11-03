{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		arduino
		screen # serial console

		gnumake
		gcc
	];

	shellHook = ''
		export PATH+=":${pkgs.arduino}/share/arduino/hardware/arduino/tools/avr/bin"
		zsh
	'';
}

