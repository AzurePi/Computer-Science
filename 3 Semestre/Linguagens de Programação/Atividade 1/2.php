<?php
function media($a, $b){
  return ($a+$b)/2;
}

$a = (float)readline('Digite um número: ');
$b = (float)readline('Digite outro número: ');
$media = media($a,$b);
echo "Média: $media\n";
?>
