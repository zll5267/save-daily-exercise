http://peak.telecommunity.com/DevCenter/PkgResources
project/release/distribute/importable distribute/pluggable distribution/extra

eggs: development eggs(ProjectName.egg-info)/built eggs(EGG_INFO)/ egg links(*.egg-link)

WorkingSet

Environment

Requirement

EntryPoint

Distribution

ResourceManager

IMetadataProvider

custome importer

import pkg_resources
pkg_resources.get_distribution("letsencrypt==0.1.0.dev0")
