<?php
// stdout.php
class stdout {
	public static function write($input){
		$stdout = fopen("php://stdout", 'w');
		fwrite($stdout, $input);
		fclose($stdout);
	}
	public static function writeln($input){
		$stdout = fopen("php://stdout", 'w');
		fwrite($stdout, $input . "\n");
		fclose($stdout);
	}
	public static function clear(){
		$stdout = fopen("php://stdout", 'w');
		fwrite($stdout, "\033[2J");
		fclose($stdout);
	}
}
/*
function main(){
	stdout::writeln("Hello World!");
}
*/
?>