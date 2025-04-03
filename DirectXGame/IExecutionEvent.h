#pragma once
#include <string>

/// <summary>
/// Listener for calling specific functions after a thread has finished execution.
/// </summary>
namespace gd
{
	class IExecutionEvent
	{
	public:
		//virtual void onFinishedExecution() = 0;
		virtual void onFinishedModelDownload(const std::string& filePath) = 0;
	};
}

