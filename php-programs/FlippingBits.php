<!-- # Flipping Bits
    You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) and print the result as an unsigned integer.

    Function Description
        Complete the flippingBits function in the editor below. It should return the unsigned decimal integer result.

    flippingBits has the following parameter(s):
        n: an integer

    Input Format
        The first line of the input contains the number of queries.
        Each of the next  lines contain an integer to process.


    Output Format
        Output one line per element from the list with the decimal value of the resulting unsigned integer.

    Sample Input 0
        3
        2147483647
        1
        0

    Sample Output 0
        2147483648
        4294967294
        4294967295


    Sample Input 1
        2
        4
        123456

    Sample Output 1
        4294967291
  
        4294843839


    Sample Input 2
        3
        0
        802743475
        35601423

    Sample Output 2
        4294967295
        3492223820
        4259365872
-->
<?php

// Complete the flippingBits function below.
function flippingBits($n)
{
    $res = 0;
    $base = 1;
    for ($i = 0; $i < 32; ++$i) {
        if ($n == 0) {
            $res += $base;
        } else {
            if ($n % 2 == 0) {
                $res += $base;
            }
            $n /= 2;
        }
        $base *= 2;
    }
    return $res;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $q);

for ($q_itr = 0; $q_itr < $q; $q_itr++) {
    fscanf($stdin, "%ld\n", $n);

    $result = flippingBits($n);

    fwrite($fptr, $result . "\n");
}

fclose($stdin);
fclose($fptr);
