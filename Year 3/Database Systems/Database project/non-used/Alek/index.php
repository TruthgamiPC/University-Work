<?php
//including the connection php code.
include 'connection.php';

//opening a connection
$conn = openCon();

//Test echo, this should be the second time this will show.
//echo "Connected Successfully";

$testQ = "SELECT * FROM branch";

if($result = $conn->query($testQ)){
    if($result->num_rows > 0){
        echo "<table>";
            echo "<tr>";
                echo "<th>IDbranch</th>";
                echo "<th>contactNumber</th>";
            echo "</tr>";
        while($row = $result->fetch_array()){
            echo "<tr>";
                echo "<td>" . $row['IDbranch'] . "</td>";
                echo "<td>" . $row['contactNumber'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
        // Free result set
        $result->free();
    } else{
        echo "No records matching your query were found.";
    }
} else {
    echo "ERROR: Could not able to execute $testQ. " . $conn->error;
}

closeCon($conn);
?>
