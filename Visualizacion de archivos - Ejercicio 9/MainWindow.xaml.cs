using Microsoft.Win32;
using System;
using System.IO;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace TextFileViewerApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        // Evento Click del botón para cargar el archivo de texto
        private async void LoadFileButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text files (*.txt)|*.txt";

            if (openFileDialog.ShowDialog() == true)
            {
                try
                {
                    // Obtener el tamaño del archivo para calcular el progreso
                    FileInfo fileInfo = new FileInfo(openFileDialog.FileName);
                    long totalBytes = fileInfo.Length;

                    if (totalBytes == 0)
                    {
                        MessageBox.Show("El archivo está vacío.", "Error", MessageBoxButton.OK, MessageBoxImage.Warning);
                        return;
                    }

                    // Inicializar la barra de progreso
                    ProgressBar.Visibility = Visibility.Visible;
                    ProgressBar.Value = 0;

                    // Leer el archivo línea por línea de manera asíncrona
                    await ReadFileAsync(openFileDialog.FileName, totalBytes);
                }
                catch (IOException ioEx)
                {
                    MessageBox.Show($"Error al leer el archivo: {ioEx.Message}", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Ocurrió un error inesperado: {ex.Message}", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                }
                finally
                {
                    // Ocultar la barra de progreso al finalizar la operación
                    ProgressBar.Visibility = Visibility.Collapsed;
                }
            }
        }

        // Método para leer el archivo línea por línea y actualizar la barra de progreso
        private async Task ReadFileAsync(string filePath, long totalBytes)
        {
            long bytesRead = 0;
            using (StreamReader reader = new StreamReader(filePath))
            {
                string line;
                TextDisplayBox.Text = string.Empty;

                while ((line = await reader.ReadLineAsync()) != null)
                {
                    // Mostrar cada línea en el TextBox
                    TextDisplayBox.AppendText(line + Environment.NewLine);

                    // Actualizar el número de bytes leídos y la barra de progreso
                    bytesRead += line.Length * sizeof(char);
                    ProgressBar.Value = (double)bytesRead / totalBytes * 100;
                }
            }
        }

        private void IncreaseFontSize_Click(object sender, RoutedEventArgs e)
        {
            if (TextDisplayBox.FontSize < 30)
            {
                TextDisplayBox.FontSize += 2;
            }
        }

        private void DecreaseFontSize_Click(object sender, RoutedEventArgs e)
        {
            if (TextDisplayBox.FontSize > 8)
            {
                TextDisplayBox.FontSize -= 2;
            }
        }
    }
}
