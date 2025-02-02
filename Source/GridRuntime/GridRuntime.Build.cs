namespace UnrealBuildTool.Rules
{
	public class GridRuntime : ModuleRules
	{
		public GridRuntime(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;
			bUseUnity = false;
			ShadowVariableWarningLevel = WarningLevel.Error;

			PublicIncludePaths.AddRange(
				new string[]
				{
					// ... add public include paths required here ...
				}
			);

			PrivateIncludePaths.AddRange
			(
				new string[]
				{
					// ... add other private include paths required here ...
				}
			);

			PublicDependencyModuleNames.AddRange
			(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"AIModule",
					"RenderCore",
					"NavigationSystem",
					"GameplayTags"
					// ... add other public dependencies that you statically link with here ...
				}
			);

			PrivateDependencyModuleNames.AddRange
			(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
			);

			DynamicallyLoadedModuleNames.AddRange
			(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
			);
		}
	}
}