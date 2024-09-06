// Animal.cs
using System;

namespace VeterinariaSimulador
{
    public abstract class Animal
    {
        protected static Random random = new Random();
        private bool auxiliarComer, auxilitarDormir;
        protected static string[] nombresAleatorios = { "Max", "Bella", "Luna", "Charlie", "Lucy", "\n\n\n", "FacundoGomez", "Manuel", "Edgar", "Gonza", "Sol", "David" };

        public string Nombre { get; protected set; }
        public bool ComeBien { get; protected set; }
        public bool DuermeBien { get; protected set; }

        public Animal()
        {
            Nombre = nombresAleatorios[random.Next(nombresAleatorios.Length)];
            // Los estados de comer y dormir son aleatorios
       
            auxiliarComer = random.Next(2) == 1;   // True si come bien, False si no
            auxilitarDormir = random.Next(2) == 1;  // True si duerme bien, False si no
            ComeBien = auxiliarComer;
            DuermeBien = auxilitarDormir;
            Comer(auxiliarComer);
            Dormir(auxilitarDormir);
        }

        // Método abstracto que será sobrescrito en las clases derivadas
        public abstract string Actividad();

        public abstract void Comer(bool auxiliarComer);
        public abstract void Dormir(bool auxilitarDormir);

        public abstract string EstadoDormir();

        public abstract string EstadoComer();
    }
}
