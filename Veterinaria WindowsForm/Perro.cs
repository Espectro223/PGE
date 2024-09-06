// Perro.cs
using System;
using System.Media;

namespace VeterinariaSimulador
{
    public class Perro : Animal
    {
        private SoundPlayer soundPlayer;
        private string estadoComer, estadoDormir;
        public Perro()
        {
            soundPlayer = new SoundPlayer("perro_ladrido.wav");
        }

        public override void Comer(bool auxiliarComer)
        {
            if (auxiliarComer == true)
            {
                estadoComer = "El perro está comiendo";
            }
            else
            {
                estadoComer = "El perro no está comiendo";
            }

        }

        public override void Dormir(bool auxilitarDormir)
        {
            if (auxilitarDormir == true)
            {
                estadoDormir = "El perro está durmiendo";
            }
            else
            {
                estadoDormir = "El perro no está durmiendo";
            }

        }

        public override string EstadoDormir()
        {
            return estadoDormir;
        }

        public override string EstadoComer()
        {
            return estadoComer;
        }

        public override string Actividad()
        {
            // Reproducir el sonido del perro
            //soundPlayer.Play();
            return $"{Nombre} ladra";
        }
    }
}
