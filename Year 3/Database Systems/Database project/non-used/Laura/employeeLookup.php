<head>

  <style>

    hr.solid {
      border-top: 3px solid #bbb;
    }

    .border {
      border-right-style: solid;

    }

    #searchBox {

    }

    label {
    	padding: 0 !important;
    	margin-top: 10px !important;
    }

  </style>

</head>


<?php
include 'header.php';
?>

<div class="container">

  <div class="containerTopBottom2">
    <div class="row">
      <div class="col">
        <h3> Colleague Look Up</h3>
      </div>
    </div>
  </div>


  <div id="searchBox">
    <div class="containerTopBottom2">

      <div class="row">
        <div class="col">
          <label>Search by name: </label>
        </div>
        <div class="col-9">
          <input class="form-control" type="text" placeholder="Search" aria-label="Search" value="">
        </div>
      </div>

      <div class="row">
      	<div class="col">
      		<label> Branch: </label>	
      	</div>
      	<div class="col">
      		<input class="form-control" type="text" placeholder="Search" aria-label="Search" value="">
      	</div>
      	<div class="col">
      		<label> ID: </label>	
      	</div>
      	<div class="col">
      		<input class="form-control" type="text" placeholder="Search" aria-label="Search" value="">
      	</div>
      </div>

    </div>
  </div>


  <div class="containerTopBottom2" >

    <div class="row">
      <div class="col-sm border">
        <h3> Customer ID </h3> 
      </div>
      <div class="col-sm">
        <h3> Customer Name </h3> 
      </div>
    </div>

    <hr class="solid">

    <div class="row">
      <div class="col-sm border">
        <p> 5682112876 </p> 
      </div>
      <div class="col-sm">
        <p> Elisaveta Peeva </p> 
      </div>
    </div>

    <div class="row">
      <div class="col-sm border">
        <p> 45463456546 </p> 
      </div>
      <div class="col-sm">
        <p> Laura Hutchison </p> 
      </div>
    </div>

    <div class="row">
      <div class="col-sm border">
        <p> 78654534263 </p> 
      </div>
      <div class="col-sm">
        <p> Preslav Petrov </p> 
      </div>
    </div>

    <div class="row">
      <div class="col-sm border">
        <p> 1239648895 </p> 
      </div>
      <div class="col-sm">
        <p> Iliyan Zvezdev  </p> 
      </div>
    </div>

  </div>

</div>


<?php
include 'footer.php';
?>
