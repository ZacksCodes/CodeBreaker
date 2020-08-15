#include "../inc/vue_mastermind.h"
#include <stdlib.h>
#include <stdio.h>

//functions
void optionsMenu();
void submit(GtkWidget* button, gpointer window);
void checkRadioBtn();

//Globals
GtkWidget *option1, *option2, *option3;
int selectedRadio = 0;
vue_master_t master;

int main(int argc, char* argv[])
{
    //vue_master_t master;

    gtk_init(NULL, NULL);
    //vue_mastermind(&master);
    optionsMenu();

    //gtk_widget_show_all(master.window);
    gtk_main();
    return EXIT_SUCCESS;
}


void optionsMenu()
{
    GtkWidget *window, *submitBtn, *cancelBtn;
    GtkWidget *label, *optionsgrid;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_window_set_title(GTK_WINDOW(window), "Options Menu");

    label = gtk_label_new ("Which mode you wanna play: ");

    option1 = gtk_radio_button_new_with_label (NULL, "Easy Mode");
    option2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (option1), "Medium Mode");
    option3 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (option1), "Hard Mode");

    optionsgrid = gtk_table_new(5,1,TRUE);
    gtk_container_add (GTK_CONTAINER(window), optionsgrid);

    gtk_table_attach(GTK_TABLE (optionsgrid), label, 0, 2, 0, 1, GTK_EXPAND, GTK_EXPAND,0, 0);
    gtk_table_attach (GTK_TABLE (optionsgrid), option1, 0, 2, 1, 2,GTK_EXPAND, GTK_EXPAND, 0, 0);
    gtk_table_attach (GTK_TABLE (optionsgrid), option2, 0, 2, 2, 3, GTK_EXPAND, GTK_EXPAND, 0, 0);
    gtk_table_attach (GTK_TABLE (optionsgrid), option3, 0, 2, 3, 4, GTK_EXPAND, GTK_EXPAND, 0, 0);

    submitBtn = gtk_button_new_with_label ("Submit");
    gtk_widget_set_size_request(submitBtn, 70, 30);
    gtk_table_attach (GTK_TABLE (optionsgrid), submitBtn, 1, 2, 4, 5, GTK_EXPAND, GTK_EXPAND, 0, 0);

    cancelBtn = gtk_button_new_with_label ("Cancel");
    gtk_widget_set_size_request(cancelBtn, 70, 30);
    gtk_table_attach (GTK_TABLE (optionsgrid), cancelBtn, 0, 1, 4, 5, GTK_EXPAND, GTK_EXPAND, 0, 0);

    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(submitBtn), "clicked",G_CALLBACK(submit), window);
    
    gtk_widget_show_all(window);
    gtk_main();
}

void submit(GtkWidget* button, gpointer window)
{
    checkRadioBtn();
    g_print("Selected Radio : %d\n",selectedRadio);
    gtk_widget_destroy(window);
    
    vue_mastermind(&master);
    GtkSettings* default_settings = gtk_settings_get_default();
	g_object_set(default_settings, "gtk-button-images", TRUE, NULL);
    gtk_widget_show_all(master.window);
}

void checkRadioBtn()
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (option1)) == TRUE)
    {
        selectedRadio = 1;
    }else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (option2)) == TRUE)
    {
        selectedRadio = 2;
    }else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (option3)) == TRUE)
        selectedRadio = 3;
}