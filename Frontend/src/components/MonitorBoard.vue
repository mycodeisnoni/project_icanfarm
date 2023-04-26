.<template>
  <div class="container">
    <div class="item1">
      <div class="nav1">
        <div class="ICON"></div>
        <div>User Name</div>
        <div class="dropdown">
          <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown" aria-expanded="false">허브명</button>
          <ul class="dropdown-menu">
            <li><a class="dropdown-item" href="#">Action</a></li>
            <li><a class="dropdown-item" href="#">Another action</a></li>
            <li><a class="dropdown-item" href="#">Something else here</a></li>
          </ul>
        </div>
      </div>
      <div class="nav2">
        <div>
          <router-link to="/rpi" style="text-decoration: none; color: black;">RPi PW</router-link>
        </div>
        <div>
          <router-link to="/" style="text-decoration: none; color: black;">LOGOUT</router-link>
        </div>
      </div>
      <router-view/>
    </div>

    <div class="uptime">
      <span>UPTIME</span>
      <span style="background-color: rgb(61, 91, 101)">h</span>
    </div>

    <div class="item2">
      <div class="monitor">
        <div class="temperature">
          Temperature
          <div></div>
        </div>
        <div class="humidity">
          Humidity
        </div>
        <div class="co2">
          CO2
        </div>
      </div>
      <div class="control">
        <div class="Set_Module">
          <div class="setting">
            <div class="name">Setting</div>
            <div>
              <thead>
                <tr style="text-align: center">
                  <th>SENSOR</th>
                  <th>LOW</th>
                  <th>HIGH</th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <th>TEMP (°C)</th>
                  <th><input type="text" size="3"></th>
                  <th><input type="text" size="3"></th>
                </tr>
                <tr>
                  <th>WATER (%)</th>
                  <th><input type="text" size="3"></th>
                  <th><input type="text" size="3"></th>
                </tr>
                <tr>
                  <th>LIGHT (H)</th>
                  <th><input type="text" size="3"></th>
                  <th><input type="text" size="3"></th>
                </tr>
              </tbody>
              <button type="button" class="btn btn-primary" @click="openModal">SET</button>
            </div>
          </div>
          <div class="module">
            <div class="name">Module</div>
            <div>
              content
            </div>
          </div>
        </div>
        <div class="dashboard">
          <div class="name">Dashboard</div>
          <div style="background-color: white">
            <thead>
                <tr>
                  <th>Timeline</th>
                  <th>LOG</th>
                  <th>Message</th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <th>Date</th>
                  <th>log</th>
                  <th>message</th>
                </tr>
              </tbody>
          </div>
        </div>
      </div>
    </div>

    <div class="modal" v-if="isModalOpen">
      <div class="modal-content">
        <span class="close" @click="closeModal">&times;</span>
        <p>Modal Content</p>
      </div>
    </div>

  </div>
</template>

<script>
export default {
  data() {
    return {
      isModalOpen: false,
    };
  },
  methods: {
    openModal() {
      this.isModalOpen = true;
    },
    closeModal() {
      this.isModalOpen = false;
    },
  },
}
</script>

<style scoped>
.item1{
  display: flex;
  justify-content: space-between;
  background-color: rgb(169, 201, 202);
  height: 20%;
  
}
.nav1{
  display: flex;
  align-items: center;
}
.nav2{
  display: flex;
  align-items: center;
  color: white;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 81px;
  height: 91px;
  Top: 35px;
  Left: 32px;
}
.uptime{
  background-color: rgb(45, 51, 51);
  color: white;
  font-size: 32px;
  /* margin: 0px, 30px; */
  text-align: right;
}
.item2{
  display: flex;
  background-color: rgb(45, 51, 51);
}
.monitor{
  color: white;
  font-size: 36px;
  width: 60%;
}
.control{
  /* background-color: rgb(90, 100, 100); */
  width: 40%;
}
.Set_Module{
  display: flex;
}
.name{
  color: black;
  font-size: 32px;
  text-align: center;
  background-color: rgb(169, 201, 202);
  /* width: 400px; */
}
.setting{
  background-color: rgb(90, 100, 100);
  width: 50%;
}
.module{
  background-color: rgb(90, 100, 100);
  width: 50%;
}


.modal {
  display: block;
  position: fixed;
  z-index: 1;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.4);
}

.modal-content {
  background-color: white;
  margin: 15% auto;
  padding: 20px;
  border: 1px solid #888;
  width: 80%;
}

.close {
  color: #aaaaaa;
  float: right;
  font-size: 28px;
  font-weight: bold;
}

.close:hover,
.close:focus {
  color: #000;
  text-decoration: none;
  cursor: pointer;
}
</style>