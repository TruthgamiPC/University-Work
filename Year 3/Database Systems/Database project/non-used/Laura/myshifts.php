<?php
include 'header.php';
include 'employeeNavbar.php';


$placeholderDate = "13/12/2020";
$placeholderShift = "9:00-14:00"

?>


<div class="container">
  <div class ="containerTopBottom">
  <div class = "row">Please pick a range of dates to view your shifts for that period.</div></div>
  <div class = "containerTopBottom2">
    <div class="row">

    <div class="col">
      <label for="start">Start date:</label>

    </div>

    <div class="col">
      <label for="end">End date:</label>
    </div>
  </div>

  <div class = "row">
    <div class = "col">
      <input type="date" id="start" name="shiftstart" value="2020-01-01" min="2020-01-01" max="2021-12-31">
    </div>
    <div class = "col">
      <input type="date" id="end" name="shiftend" value="2020-01-01" min="2020-01-01" max="2021-12-31">
    </div>
  </div>
</div>
</div>



  <div id="center">
    <div class="staffInfo">
      <div id="employeeInfo">
        <h3>Shifts DATE to DATE</h3>
        <div class="info">
          <div class="row">
            <div class="col">
              <div class="column">
                <b><?php echo $placeholderDate ?></b>
              </div>
            </div>

            <div class="col">
              <div class="column">
                <b><?php echo $placeholderShift ?></b>
              </div>
            </div>

          </div>

          <!-- cycle thru each shift from date to date?? -->

        </div>

      </div>
    </div>
  </div>
  <!-- php for grabbing shifts - populating table with info???? -->

  <?php
include 'footer.php';
?>
