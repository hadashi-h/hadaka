<div class="container">
  <div class="row">
    <div class="box user-box">
      <h1>Hello Hubert!</h1>
      <img src="<?php echo $imgUrl ?>/hubert.png"/>
      <h3>Take a look at your Account Balance! It's coming along nicely</h3>
    </div>

    <div class="big-box money-box">
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
              <td>Card purchase</td><td>$ -79,62</td><td><button type="button" class="btn-flat">details</button></td>
            </tr>
            <tr>
              <td>Incoming transfer</td><td>$ 195,25</td><td><button type="button" class="btn-flat">details</button></td>
            </tr>
            <tr class="even">
              <td>Web payment</td><td>$ 56,65</td><td><button type="button" class="btn-flat">details</button></td>
            </tr>
            <tr>
              <td>Incoming transfer</td><td>$ 523</td><td><button type="button" class="btn-flat">details</button></td>
            </tr>
          </table>
      </div>
    </div>
</div>
