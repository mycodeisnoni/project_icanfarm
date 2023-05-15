<template>
  <div class="container">
    <div class="item1">
      <div class="nav1">
        <div class="ICON"></div>
        <div style="font-size: 24px;">User Name</div>
        <div><button v-bind:title="default_hub">Hub No. {{ default_hub }}</button></div>
        <!-- <div class="dropdown">
          <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown" aria-expanded="false">허브명</button>
          <ul class="dropdown-menu">
            <li><a class="dropdown-item" href="#">Hub No. 1</a></li>
            <li><a class="dropdown-item" href="#">Hub No. 2</a></li>
            <li><a class="dropdown-item" href="#">Hub No. 3</a></li>
          </ul>
        </div> -->
      </div>
      <div class="nav2">
        <div><router-link to="/rpi" style="text-decoration: none; color: black;">RPi PW</router-link></div>
        <router-view/>
        <div><a href="/" style="text-decoration: none; color: black;" @click="logout">LOGOUT</a></div>
      </div>
    </div>

    <div class="uptime">
      <span>UPTIME</span>
      <span style="background-color: rgb(61, 91, 101)">{{ uptime }}h</span>
    </div>

    <div class="item2">
      <div class="monitor">
        <div class="temperature">
          <div class="Set_label">Temperature</div>
          <div class="chart-container">
            <div class="chart-wrapper"><doughnut-chart :data="TempDonutChart" :options="donutChartOptions" /></div>
            
          </div>
        </div>
        <div class="humidity">
          <div class="Set_label">Humidity</div>
          <div class="chart-container">
            <!-- <canvas id="Humid-Chart"></canvas> -->
            <doughnut-chart :data="HumidDonutChart" :options="donutChartOptions" />
          </div>
        </div>
        <div class="co2">
          <div class="Set_label">CO2</div>
          <div class="chart-container">
            <doughnut-chart :data="CO2DonutChart" :options="donutChartOptions" />
            <!-- <canvas id="CO2-Chart"></canvas> -->
          </div>
        </div>
      </div>

      <div class="control">
        <div class="Set_Module">
          <div class="setting">
            <div class="name">Setting</div>
            <div style="font-size: 130%; padding: 10px; display: flex; flex-direction: column; justify-content: center; align-items: center;">
              <tbody style="border-spacing: 20px;">
                <tr style="text-align: center;">
                  <th>SENSOR</th>
                  <th>TARGET</th>
                  <th>RANGE</th>
                </tr>
                <tr>
                  <th>TEMP (°C)</th>
                  <th><input type="text" :placeholder="tempTarget" v-model.lazy="tempTarget" size="3"></th>
                  <th><input type="text" :placeholder="tempRange" v-model.lazy="tempRange" size="3"></th>
                </tr>
                <tr>
                  <th>WATER (%)</th>
                  <th><input type="text" :placeholder="humidTarget" v-model.lazy="humidTarget" size="3"></th>
                  <th><input type="text" :placeholder="humidRange" v-model.lazy="humidRange" size="3"></th>
                </tr>
                <tr>
                  <th>LIGHT (H)</th>
                  <th><input type="text" :placeholder="startTimeHour" v-model.lazy="startTimeHour" size="3"></th>
                  <th><input type="text" :placeholder="endTimeHour" v-model.lazy="endTimeHour" size="3"></th>
                </tr>
              </tbody>
              <button type="button" style="font-size: 24px; height: 50px; width: 100px; margin-top: 20px;" @click="openModal">SET</button>
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
        <h2>Settings</h2>
        <p>Temperature Target : {{ tempTarget }}</p>
        <p>Temperature Range : {{ tempRange }}</p>
        <p>Humid Target : {{ humidTarget }}</p>
        <p>Humid Range : {{ humidRange }}</p>
        <p>Start Time : {{ startTimeHour }}</p>
        <p>End Time : {{ endTimeHour }}</p>
        <div>변경 완료</div>
      </div>
    </div>

  </div>
</template>

<script>
import Chart from 'chart.js/auto';
import { api } from "@/utils/axios";
import DoughnutChart from '@/components/DoughnutChart.vue';

export default {
  name: 'LineChart',
  components: {
    DoughnutChart,
  },
  data() {
    return {
      userName: "",
      default_hub: null,
      uptime: 0,
      intervalId: null,
      isModalOpen: false,
      temp_table: null,
      humid_table: null,
      co2_table: null,
      tempTarget: "",
      tempRange: "",
      humidTarget: "",
      humidRange: "",
      lightTarget: "",
      lightRange: "",
      startTimeHour: null,
      endTimeHour: null,
      TempDonutChart: {
        labels: ['Red', 'Gray'],
        datasets: [
          {
            data: [35, 50-35],
            backgroundColor: ['#FF6384', '#D9D9D9'],
            borderWidth: 1,
          },
        ],
      },
      HumidDonutChart: {
        labels: ['Yellow', 'Gray'],
        datasets: [
          {
            data: [30, 30],
            backgroundColor: ['#F5D800', '#D9D9D9'],
            borderWidth: 1,
          },
        ],
      },
      CO2DonutChart: {
        labels: ['Green', 'Gray'],
        datasets: [
          {
            data: [12, 19],
            backgroundColor: ['#4BAE7A', '#D9D9D9'],
            borderWidth: 1,
          },
        ],
      },
      donutChartOptions: {
        responsive: true,
        maintainAspectRatio: false,
        cutout: 90,
        plugins: {
          legend: {
            display: false,
          },
        },
      },
    };
  },
  async mounted(){
    this.member_id = localStorage.getItem('user');
    await api.member.getDefaultHub(this.member_id)
    .then((res) => {
      this.default_hub = res.data;
    })
    .catch((err) => {
      console.log('ERROR');
    });
    // this.adjustChartHeight();
    this.getSettings();
    const startTime = localStorage.getItem('startTime');
    if(startTime){
      this.startTime = new Date(parseInt(startTime));
      this.intervalId = setInterval(this.updateUptime, 1000);
    }
  },
  beforeRouteLeave(to, from, next) {
  localStorage.setItem('startTime', this.startTime.getTime());
  next();
  },
  methods: {
    // adjustChartHeight() {
    //   this.$nextTick(() => {
    //     const containerHeight = this.$refs.chartContainer.offsetHeight;
    //     this.$refs.chartContainer.style.height = `${containerHeight}px`;
    //   });
    // },
    logout(){
      localStorage.removeItem('user');
      localStorage.removeItem('startTime');
    },
    updateUptime(){
      const now = new Date();
      const diff = now.getTime() - this.startTime.getTime();
      this.uptime = (diff/(1000*60*60)).toFixed(2);
    },
    async getSettings() {
      try{
        const [tempTargetRes, tempRangeRes, humidTargetRes, humidRangeRes, lightRes] = await Promise.all([
          api.hub.getTempTarget(this.default_hub),
          api.hub.getTempRange(this.default_hub),
          api.hub.getHumidTarget(this.default_hub),
          api.hub.getHumidRange(this.default_hub),
          api.hub.getLightSet(this.default_hub),
        ]);
        this.tempTarget = tempTargetRes.data.value;
        this.tempRange = tempRangeRes.data.value;
        this.humidTarget = humidTargetRes.data.value;
        this.humidRange = humidRangeRes.data.value;
        this.startTimeHour = Number.parseInt(lightRes.data.startTime.slice(11, 13));
        this.endTimeHour = Number.parseInt(lightRes.data.endTime.slice(11, 13));
      } catch (err) {
        console.log('ERROR: ', err);
        throw err;
      };

    },
    async openModal() {
      const now = new Date();
      const year = now.getFullYear();
      const month = String(now.getMonth() + 1).padStart(2, "0");
      const day = String(now.getDate()).padStart(2, "0");

      const formatTime = (time) => String(time).padStart(2, "0");
      try{
        await Promise.all([
          api.hub.setTempTarget({rpi_id: this.default_hub, value: this.tempTarget}).then((res) => console.log("1")),
          api.hub.setTempRange({rpi_id: this.default_hub, value: this.tempRange}).then((res) => console.log("2")),
          api.hub.setHumidTarget({rpi_id: this.default_hub, value: this.humidTarget}).then((res) => console.log("3")),
          api.hub.setHumidRange({rpi_id: this.default_hub, value: this.humidRange}).then((res) => console.log("4")),
          api.hub.setLightSet({
            rpi_id: this.default_hub, 
            startTime: `${year}-${month}-${day}T${formatTime(this.startTimeHour)}:00:00`,
            endTime: `${year}-${month}-${day}T${formatTime(this.endTimeHour)}:00:00`},)
        ]);
        console.log("모든 API 콜 성공")
        this.isModalOpen = true;
      } catch (err) {
        console.log("ERROR: ", err);
      };
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
  /* justify-content: space-between; */
  background-color: rgb(169, 201, 202);
  position: absolute;
  width: 100%;
  height: 10%;
  top: 0;
  left: 0;
}
.item1 > *{
  margin: 0px 10px;
}
.item1 > * > div{
  margin: 0px 7px;
}
.nav1{
  display: flex;
  align-items: center;
  margin-right: auto;
}
.nav2{
  display: flex;
  align-items: center;
  color: white;
  margin-left: auto;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 81px;
  height: 91px;
}
.uptime{
  background-color: rgb(45, 51, 51);
  color: white;
  font-size: 32px;
  position: absolute;
  width: 100%;
  height: 5%;
  top: 10%;
  left: 0%;
  text-align: right;
}
.item2{
  display: flex;
  background-color: rgb(45, 51, 51);
  position: absolute;
  width: 100%;
  height: 85%;
  top: 15%;
  left: 0;
}
.monitor{
  color: white;
  font-size: 36px;
  width: 60%;
}
/* .monitor > * > *{
  border: 1px black solid;
} */
.chart-container{
  position: relative;
  top: 0px;
  height: 10%;
  width: 100%;
  background-color: white;
}
.chart-wrapper {
  display: flex;
  align-items: center;
  flex: 1;
}

.control{
  /* background-color: rgb(90, 100, 100); */
  position: relative;
  width: 40%;
  
}
.Set_Module{
  display: flex;
  height: 50%;
}
.name{
  color: black;
  font-size: 32px;
  font-weight: bold;
  text-align: center;
  background-color: rgb(169, 201, 202);
  /* width: 400px; */
}
/* .name > tbody > tr > th{
  margin: 0px 20px;
} */
.setting{
  background-color: rgb(90, 100, 100);
  width: 50%;
}
.module{
  background-color: rgb(90, 100, 100);
  width: 50%;
}
.dashboard{
  /* height: 50%; */
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