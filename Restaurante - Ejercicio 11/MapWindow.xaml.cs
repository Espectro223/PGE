﻿using System;
using System.Windows;
using System.Windows.Media.Imaging;

namespace FoodExplorer
{
    public partial class MapWindow : Window
    {
        public MapWindow(string product)
        {
            InitializeComponent();
            ShowMapForProduct(product);
        }

        private void ShowMapForProduct(string product)
        {
            string mapUrl;

            // Mapeamos las URLs del mapa según el producto seleccionado
            switch (product)
            {
                case "Cheeseburger":
                    mapUrl = "https://css-tianguis.com/wp-content/uploads/2020/03/google-maps-links.png"; // URL del mapa para Cheeseburger
                    MapTitle.Text = "Ubicación del restaurante para Cheeseburger";
                    break;
                case "Bacon Burger":
                    mapUrl = "https://www.elclarinete.com.mx/wp-content/uploads/2017/12/google-maps.png"; // URL del mapa para Bacon Burger
                    MapTitle.Text = "Ubicación del restaurante para Bacon Burger";
                    break;
                case "Sicilian Pizza":
                    mapUrl = "https://i.sstatic.net/B6fEt.png"; // URL del mapa para Sicilian Pizza
                    MapTitle.Text = "Ubicación del restaurante para Sicilian Pizza";
                    break;
                case "Pepperoni Pizza":
                    mapUrl = "https://css-tianguis.com/wp-content/uploads/2020/03/google-maps-links.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Pepperoni Pizza";
                    break;
                case "Hawaiian Pizza":
                    mapUrl = "https://www.elclarinete.com.mx/wp-content/uploads/2017/12/google-maps.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Hawaiian Pizza";
                    break;
                case "Chocolate Cake":
                    mapUrl = "https://i.sstatic.net/B6fEt.png";
                    MapTitle.Text = "Ubicación del restaurante para Chocolate Cake";
                    break;
                case "Ice Cream Sundae":
                    mapUrl = "https://css-tianguis.com/wp-content/uploads/2020/03/google-maps-links.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Ice Cream Sundae";
                    break;
                case "French Fries":
                    mapUrl = "https://www.elclarinete.com.mx/wp-content/uploads/2017/12/google-maps.png"; 
                    MapTitle.Text = "Ubicación del restaurante para French Fries";
                    break;
                case "Croissant":
                    mapUrl = "https://i.sstatic.net/B6fEt.png";
                    MapTitle.Text = "Ubicación del restaurante para Croissant";
                    break;
                case "Lemonade":
                    mapUrl = "https://i.sstatic.net/B6fEt.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Lemonade";
                    break;
                case "Iced Coffee":
                    mapUrl = "https://css-tianguis.com/wp-content/uploads/2020/03/google-maps-links.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Iced Coffee";
                    break;
                case "Kung Pao Chicken":
                    mapUrl = "https://www.elclarinete.com.mx/wp-content/uploads/2017/12/google-maps.png"; 
                    MapTitle.Text = "Ubicación del restaurante para Kung Pao Chicken";
                    break;
                case "Sweet and Sour Pork":
                    mapUrl = "https://i.sstatic.net/B6fEt.png";
                    MapTitle.Text = "Ubicación del restaurante para Sweet and Sour Pork";
                    break;
                default:
                    mapUrl = "https://www.bigbraincreation.com/bigbrain-images/bigbrain-banner/bigbrain-google-map.png"; // URL del mapa predeterminado
                    MapTitle.Text = "Ubicación predeterminada del restaurante";
                    break;
            }

            // Cargamos la imagen del mapa
            try
            {
                MapImage.Source = new BitmapImage(new Uri(mapUrl, UriKind.Absolute));
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al cargar el mapa: " + ex.Message);
            }
        }

        // Evento para cerrar la ventana del mapa
        private void CloseMap_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
