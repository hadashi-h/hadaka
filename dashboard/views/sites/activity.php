<div class="container">
  <div class="row">
    <div class="box user-box">
      <h1>Hello Hubert!</h1>
      <img src="<?php echo $imgUrl ?>/hubert.png"/>
      <h3>Take a look at your Activity Summary! You have still some work to do today</h3>
    </div>

    <div class="big-box activity-box">
      <h1>Activity</h1>
      <canvas id="activity-chart" ></canvas>

      <table cellspacing="0" cellpadding="0">
        <tr>
          <th>Last activity</th><th>Date/Time</th><th>Duration</th><th></th>
        </tr>
        <tr>
          <td>Walk</td><td>6:19 pm</td><td>15 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Run</td><td>6:00 pm</td><td>4 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Bicycle</td><td>4:54 pm</td><td>1 hour</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Walk</td><td>8:00 am</td><td>3 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Walk</td><td>7:12am</td><td>13 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Bicycle</td><td>6:30 am</td><td>30 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
      </table>
    </div> 
    </div>
</div>
