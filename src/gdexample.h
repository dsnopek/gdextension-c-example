#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include "gdextension_interface.h"

#include "defs.h"

// Struct to hold the node data.
typedef struct
{
    // Private properties.
    double time_passed;
    double time_emit;
    // Public properties.
    double amplitude;
    double speed;
    // Metadata.
    StringName position_changed; // For signal.
    GDExtensionObjectPtr object; // Stores the underlying Godot object.
} GDExample;

// Constructor for the node.
void gdexample_class_constructor(GDExample *self);

// Destructor for the node.
void gdexample_class_destructor(GDExample *self);

// Properties.
void gdexample_class_set_amplitude(GDExample *self, double amplitude);
double gdexample_class_get_amplitude(const GDExample *self);
void gdexample_class_set_speed(GDExample *self, double speed);
double gdexample_class_get_speed(const GDExample *self);

// Methods.
void gdexample_class_process(GDExample *self, double delta);

// Bindings.
void gdexample_class_bind_methods();
GDExtensionObjectPtr gdexample_class_create_instance(void *p_class_userdata);
void gdexample_class_free_instance(void *p_class_userdata, GDExtensionClassInstancePtr p_instance);
void *gdexample_class_get_virtual_with_data(void *p_class_userdata, GDExtensionConstStringNamePtr p_name);
void gdexample_class_call_virtual_with_data(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, void *p_virtual_call_userdata, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret);

#endif // GDEXAMPLE_H
