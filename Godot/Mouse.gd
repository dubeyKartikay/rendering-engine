extends CharacterBody2D

@export var acceleration = 30000;
@export var friction = 10;
@export var top_speed = 300;


@export var jump_height : float = 300
@export var jump_time_to_peak : float = 0.5
@export var jump_time_to_descent : float = 0.35

@onready var jump_velocity : float = ((2.0 * jump_height) / jump_time_to_peak) * -1.0
@onready var jump_gravity : float = ((-2.0 * jump_height) / (jump_time_to_peak * jump_time_to_peak)) * -1.0
@onready var fall_gravity : float = ((-2.0 * jump_height) / (jump_time_to_descent * jump_time_to_descent)) * -1.0
func _process(delta):
	pass

func get_gravity() -> float:
	return jump_gravity if velocity.y < 0.0 else fall_gravity
	
func _physics_process(delta):
	move_player(delta)
	move_and_slide()
	
func move_player(delta):
	var movement_direction = Input.get_axis("Left","Right")
	if(movement_direction != 0):
		velocity.x = velocity.move_toward(top_speed*movement_direction*Vector2(1,0),acceleration*delta).x
	else:
		velocity.x = velocity.move_toward(Vector2(0,velocity.y),friction*delta).x
	
	if(Input.is_action_just_pressed("Jump")):
		jump(delta)
		
	velocity.y += get_gravity() * delta

func jump(delta):
	velocity.y = jump_velocity
