using System;
using System.Windows;

namespace UnitConverterApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            // Agregar las opciones de unidades a los ComboBox
            UnitFromComboBox.ItemsSource = new string[] { "Metros", "Kilómetros", "Millas", "Pulgadas",
                                                          "Gramos", "Kilogramos", "Libras",
                                                          "Celsius", "Fahrenheit", "Kelvin" };
            UnitToComboBox.ItemsSource = new string[] { "Metros", "Kilómetros", "Millas", "Pulgadas",
                                                        "Gramos", "Kilogramos", "Libras",
                                                        "Celsius", "Fahrenheit", "Kelvin" };

            UnitFromComboBox.SelectionChanged += PerformConversion;
            UnitToComboBox.SelectionChanged += PerformConversion;
            ValueTextBox.TextChanged += PerformConversion;
        }

        // Método que realiza la conversión automática cada vez que cambian las unidades o el valor
        private void PerformConversion(object sender, EventArgs e)
        {
            // Validar que el usuario ingrese un valor numérico
            if (!double.TryParse(ValueTextBox.Text, out double inputValue))
            {
                ResultTextBlock.Text = "Ingrese un número válido.";
                return;
            }

            string unitFrom = UnitFromComboBox.SelectedItem as string;
            string unitTo = UnitToComboBox.SelectedItem as string;

            // Validar que las unidades de origen y destino hayan sido seleccionadas
            if (unitFrom == null || unitTo == null)
            {
                ResultTextBlock.Text = "Seleccione las unidades de origen y destino.";
                return;
            }

            // Intentar realizar la conversión
            try
            {
                double result = ConvertUnits(inputValue, unitFrom, unitTo);
                ResultTextBlock.Text = $"Resultado: {result} {unitTo}";
            }
            catch (InvalidOperationException ex)
            {
                ResultTextBlock.Text = ex.Message; // Mostrar el mensaje de error
            }
        }

        // Función que realiza las conversiones
        private double ConvertUnits(double value, string unitFrom, string unitTo)
        {
            // Conversión de longitud
            if (unitFrom == "Metros")
            {
                if (unitTo == "Kilómetros") return value / 1000;
                if (unitTo == "Millas") return value / 1609.34;
                if (unitTo == "Pulgadas") return value * 39.3701;
            }
            if (unitFrom == "Kilómetros")
            {
                if (unitTo == "Metros") return value * 1000;
                if (unitTo == "Millas") return value / 1.60934;
                if (unitTo == "Pulgadas") return value * 39370.1;
            }
            if (unitFrom == "Millas")
            {
                if (unitTo == "Metros") return value * 1609.34;
                if (unitTo == "Kilómetros") return value * 1.60934;
                if (unitTo == "Pulgadas") return value * 63360;
            }
            if (unitFrom == "Pulgadas")
            {
                if (unitTo == "Metros") return value / 39.3701;
                if (unitTo == "Kilómetros") return value / 39370.1;
                if (unitTo == "Millas") return value / 63360;
            }

            // Conversión de peso
            if (unitFrom == "Gramos")
            {
                if (unitTo == "Kilogramos") return value / 1000;
                if (unitTo == "Libras") return value / 453.592;
            }
            if (unitFrom == "Kilogramos")
            {
                if (unitTo == "Gramos") return value * 1000;
                if (unitTo == "Libras") return value * 2.20462;
            }
            if (unitFrom == "Libras")
            {
                if (unitTo == "Gramos") return value * 453.592;
                if (unitTo == "Kilogramos") return value / 2.20462;
            }

            // Conversión de temperatura
            if (unitFrom == "Celsius")
            {
                if (unitTo == "Fahrenheit") return (value * 9 / 5) + 32;
                if (unitTo == "Kelvin") return value + 273.15;
            }
            if (unitFrom == "Fahrenheit")
            {
                if (unitTo == "Celsius") return (value - 32) * 5 / 9;
                if (unitTo == "Kelvin") return (value - 32) * 5 / 9 + 273.15;
            }
            if (unitFrom == "Kelvin")
            {
                if (unitTo == "Celsius") return value - 273.15;
                if (unitTo == "Fahrenheit") return (value - 273.15) * 9 / 5 + 32;
            }

            // Si las unidades son iguales, devolver el mismo valor
            if (unitFrom == unitTo)
                return value;

            // Si llegamos aquí, las unidades no son compatibles
            throw new InvalidOperationException("No se puede convertir entre estas unidades.");
        }
    }
}
