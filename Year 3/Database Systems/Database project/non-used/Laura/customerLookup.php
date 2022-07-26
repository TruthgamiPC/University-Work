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

  </style>

</head>



<?php
include 'header.php';
?>


<div class="container">

  <div class="containerTopBottom2">
    <div class="row">
      <div class="col">
        <h3> Customer Lookup</h3>
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
          <input class="form-control" type="text" placeholder="Search" aria-label="Search" value="Elisaveta">
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

  </div>

</div>

<!--
<div class="container">
  <span class="border border-dark">
  <div class="containerTopBottom2">
<span class="border border-dark">
    <div class="row">
      <span class="border border-dark">
      <div class="col">
        dhsjjs
      </div>
    </span>
    <span class="border border-dark">
    <div class="col">
      dhsjjs
    </div>
  </span>
    </div>
  </span>
  </div>
</span>
</div>
-->

<?php
include 'footer.php';
?>
