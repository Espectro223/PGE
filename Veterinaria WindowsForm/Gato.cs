// Gato.cs
using System;
using System.Media;

namespace VeterinariaSimulador
{
    public class Gato : Animal
    {
        private SoundPlayer soundPlayer;
        private string estadoDormir, estadoComer;
        public Gato()
        {
            soundPlayer = new SoundPlayer("gato_maullido.wav"); // Ruta al archivo de sonido
        }

        public override void Comer(bool auxiliarComer)
        {
            if(auxiliarComer == true)
            {
                estadoComer = "El gato está comiendo";
            }
            else
            {
                estadoComer = "El gato no está comiendo";
            }
            
        }

        public override void Dormir(bool auxilitarDormir)
        {
            if (auxilitarDormir == true)
            {
                estadoDormir = "El gato está durmiendo";
            }
            else
            {
                estadoDormir = "El gato no está durmiendo";
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
            // Reproducir sonido del gato
            //soundPlayer.Play();
            return $"{Nombre} maúlla";
        }
    }
}
