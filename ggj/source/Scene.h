#pragma once
#include "Cave.h"
#include "Player.h"
#include "physac.h"

class Scene {
public:
	Scene() {
		cave.generate();
		InitPhysics();
	};

	~Scene() {
		ClosePhysics();
	}
	void render() {
		cave.render();
		player.render();

		int bodiesCount = GetPhysicsBodiesCount();
		for (int i = 0; i < bodiesCount; i++)
		{
			PhysicsBody body = GetPhysicsBody(i);

			if (body != NULL)
			{
				int vertexCount = GetPhysicsShapeVerticesCount(i);
				for (int j = 0; j < vertexCount; j++)
				{
					// Get physics bodies shape vertices to draw lines
					// Note: GetPhysicsShapeVertex() already calculates rotation transformations
					Vector2 vertexA = GetPhysicsShapeVertex(body, j);

					int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);   // Get next vertex or first to close the shape
					Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

					SDL_SetRenderDrawColor(Render::renderer, 255, 0, 0, 255);
					SDL_RenderDrawLine(Render::renderer, vertexA.x, vertexA.y, vertexB.x, vertexB.y);
				}
			}
		}


	}
	void update() {
		cave.update();
		player.update();
	}
private:
	Cave cave;
	Player player;
};