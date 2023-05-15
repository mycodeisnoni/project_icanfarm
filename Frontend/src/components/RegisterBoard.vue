<template>
  <div class="chart-wrapper">
    <doughnut-chart :data="donutChartData" :options="donutChartOptions" />
    <line-chart :chart-data="lineChartData" :chart-options="lineChartOptions" />
  </div>
</template>

<script>
import DoughnutChart from '@/components/DoughnutChart.vue';
import LineChart from '@/components/LineChart.vue';

export default {
  components: {
    DoughnutChart,
    LineChart,
  },
  data() {
    return {
      donutChartData: {
        labels: ['Red', 'Blue', 'Yellow'],
        datasets: [
          {
            label: '# of Votes',
            data: [12, 19, 3],
            backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56'],
            borderWidth: 1,
          },
        ],
      },
      donutChartOptions: {
        responsive: true,
        maintainAspectRatio: false,
        // cutoutPercentage: 90,
        cutout: 90,
        plugins: {
          legend: {
            display: false,
          },
        },
      },
      lineChartData: {
        labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
        datasets: [
          {
            label: 'My First dataset',
            borderColor: 'rgb(255, 99, 132)',
            data: [0, 10, 5, 2, 20, 30, 45],
          },
        ],
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
.chart-wrapper {
  display: flex;
  align-items: center;
}
</style>