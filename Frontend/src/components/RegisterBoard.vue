<template>
  <div class="container">
    <div class="item">
      <div class="chart-wrapper">
        <div class="graph_2">
          <DoughnutChart :data="TempDonutChart" :options="donutChartOptions"/>
        </div>
        <div class="line_g">
          <LineChart :chart-data="TempLineChart" :chart-options="lineChartOptions" />
        </div>
      </div>

    </div>

  </div>
  
</template>

<script>
import { api } from "@/utils/axios";
import DoughnutChart from '@/components/DoughnutChart.vue';
import LineChart from '@/components/LineChart.vue';

export default {
  components: {
    DoughnutChart,
    LineChart,
  },
  data() {
    return {
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
      TempLineChart: {
        labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
        datasets: [
          {
            borderColor: 'rgb(255, 99, 132)',
            data: [0, 10, 5, 2, 20, 30, 45],
          },
        ],
      },
      donutChartOptions: {
        responsive: true,
        maintainAspectRatio: false,
        cutoutPercentage: 50,
        legend: {
          display: false,
        },
      },
      lineChartOptions: {
        plugins: {
          legend: {
            display: false,
          },
        },
      },
    };
  },
};
</script>

<style scoped>
.container{
  width: 100%;
  height: 100vh; /* 화면의 높이를 100%로 설정 */
  border: 1px solid black;
}
.item{
  width: 100%;
  height: 100vh; /* 화면의 높이를 100%로 설정 */
  border: 1px solid black;
}
.chart-wrapper{
  border: 1px solid red;
  width: 100%;
  height: 50%;
  display: flex;
  justify-content: center;
}
.graph_2{
  border: 1px solid blue;
  width: 20%;
  height: 50%;
  position: relative;
}
.graph_2 > * {
  position: absolute;
  top: 0;
  bottom: 0;
  left: 0;
  right: 0;
}
.line_g{
  border: 1px solid pink;
  width: 50%;
  height: 50%;
  position: relative;
}

</style>