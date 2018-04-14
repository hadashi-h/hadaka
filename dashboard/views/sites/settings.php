<div class="container">
  <div class="row">
    <div class="box user-box">
      <h1>Hello Hubert!</h1>
      <img src="<?php echo $imgUrl ?>/hubert.png"/>
      <h3>Everything is fine, although I would keep an eye on your phone! </h3>
    </div>

    <div class="box activity-box">
      <h1>Activity</h1>
      <canvas id="activity-chart" ></canvas>

      <table cellspacing="0" cellpadding="0">
        <tr>
          <th>Last activity</th><th>Date/Time</th><th>Duration</th><th></th>
        </tr>
        <tr>
          <td>Walk</td><td>6:19 pm</td><td>15 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr class="even">
          <td>Run</td><td>6:00 pm</td><td>4 min</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Bicycle</td><td>4:54 pm</td><td>1 hour</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
      </table>
    </div>

    <div class="box money-box">
      <h1>Savings</h1>
      <canvas id="savings-chart" ></canvas>

        <table cellspacing="0" cellpadding="0">
          <tr>
            <th>Last payment</th><th>Value</th><th></th>
          </tr>
          <tr>
            <td>Card purchase</td><td>$ -9,62</td><td><button type="button" class="btn-flat">details</button></td>
          </tr>
          <tr class="even">
            <td>Web payment</td><td>$ -56,65</td><td><button type="button" class="btn-flat">details</button></td>
          </tr>
          <tr>
            <td>Incoming transfer</td><td>$ 195,25</td><td><button type="button" class="btn-flat">details</button></td>
          </tr>
        </table>

    </div>
    <div class="box computer-box">
      <h1>MyComputer</h1>

      <table cellspacing="0" cellpadding="0">
        <tr>
          <th>Last activity</th><th>Date/Time</th><th></th>
        </tr>
        <tr>
          <td>Login successful</td><td>5:19 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr class="even">
          <td>Login failure</td><td>5:18 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Login failure</td><td>4:54 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
      </table>
    </div>

    <div class="box phone-box">
      <h1>MyPhone Lenovo P780</h1>
      <table cellspacing="0" cellpadding="0">
        <tr>
          <th>Last activity</th><th>Date/Time</th><th></th>
        </tr>
        <tr>
          <td>Login failure</td><td>6:19 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr class="even">
          <td>Login failure</td><td>6:18 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
        <tr>
          <td>Login failure</td><td>6:17 pm</td><td><button type="button" class="btn-flat">details</button></td>
        </tr>
      </table>
    </div>

    <div class="box macros-box">
      <h1>Macros</h1>
      <canvas id="macros-chart" ></canvas>
    </div>
  </div>

</div>
