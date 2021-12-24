#include "Scene.h"

void Scene::UpdateSceneGameObjects(const double& elapsedTime)
{
	for (std::vector<GameObject*>::iterator it = _sceneGameObjects.begin(); it != _sceneGameObjects.end(); ++it) {
		(*it)->Update(elapsedTime);
	}
}

void Scene::RenderSceneGameObjects() const
{
	for (std::vector<GameObject*>::const_iterator it = _sceneGameObjects.begin(); it != _sceneGameObjects.end(); ++it) {
		(*it)->Render();
	}
}

void Scene::DeleteSceneGameObjects()
{
	_sceneGameObjects.clear();
}

void Scene::AddSceneGameObject(GameObject* gameObject)
{
	_sceneGameObjects.push_back(gameObject);
}
