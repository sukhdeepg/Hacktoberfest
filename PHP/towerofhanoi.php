
// I enjoy this function because it solves the Tower of Hanoi, which is crucial for winning any season of Survivor.

function towerOfHanoi($n, $from_rod, $to_rod, $aux_rod) { 
      
    if ($n === 1) { 
    echo ("Move disk 1 from rod $from_rod to rod $to_rod \n"); 
    return; 
    }  
      
    towerOfHanoi($n-1, $from_rod, $aux_rod, $to_rod); 
    echo ("Move disk $n from rod $from_rod to rod $to_rod \n"); 
    towerOfHanoi($n-1, $aux_rod, $to_rod, $from_rod); 
  
} 
