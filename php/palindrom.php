<?php

function Palindrome($str){
 // Base condition to end the recursive process
    if ((strlen($str) == 1) || (strlen($str) == 0)){
        echo "Palindrome";
    }
 
    else{
         
        // First character is compared with the last one
        if (substr($str,0,1) == substr($str,(strlen($str) - 1),1)){
             
            // Checked letters are discarded and passed for next call
            return Palindrome(substr($str,1,strlen($str) -2));
        }
        else{
            echo " Not a Palindrome"; }
    }
}
$kata1 = "kasur rusak";

if (Palindrome($kata1)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}

$kata2 = "malam";
if (Palindrome($kata2)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}


$kata3 = "malkam";

if (Palindrome($kata3)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}

$kata4 = "recevar";
if (Palindrome($kata4)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}

$kata5 = "lesvel" ;

if (Palindrome($kata5)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}
$kata6 = "tofu";
if (Palindrome($kata6)){ 
    echo "Palindrome"; 
}
else { 
  echo "Not a Palindrome"; 
}

	
?>